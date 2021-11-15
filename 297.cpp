#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  void Print() {
    cout << val << " ";
    if (left)
      left->Print();
    else
      cout << "null ";
    if (right)
      right->Print();
    else
      cout << "null ";
  }
};

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string ret;
    ret += '[';
    /* 层序遍历 */
    if (root) {
      vector<TreeNode *> nodes;
      queue<TreeNode *> que;

      que.push(root);
      nodes.push_back(root);
      while (!que.empty()) {
        auto node = que.front();
        que.pop();
        auto left = node->left;
        if (left)
          que.push(left);
        nodes.push_back(left);
        auto right = node->right;
        if (right)
          que.push(right);
        nodes.push_back(right);
      }

      while (!nodes[nodes.size() - 1])
        nodes.pop_back();

      auto len = nodes.size();
      for (int i = 0; i < len; i++) {
        if (nodes[i]) {
          ret += to_string(nodes[i]->val) + ',';
        } else {
          ret += "null,";
        }
      }
      if (len) {
        ret.pop_back();
      }
    }
    ret += ']';
    return ret;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    auto len = data.length();
    if (len <= 2)
      return nullptr;
    // TreeNode *root = nullptr;
    deque<TreeNode *> nodes;
    auto i = 0;
    auto last_dot = 0;
    while (i < len) {
      switch (data[i]) {
      case '[':
        break;
      case ' ':
        break;
      case ']':
      case ',': {
        auto val = &data[last_dot + 1];
        if (i - last_dot == 5 && val[0] == 'n' && val[1] == 'u' &&
            val[2] == 'l' && val[3] == 'l') {
          nodes.push_back(nullptr);
        } else {
          nodes.push_back(new TreeNode(atoi(val)));
        }
        last_dot = i;
        break;
      }
      default:
        break;
      }
      i++;
    }

    TreeNode *node;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    int nodes_lens = nodes.size();
    if (nodes_lens == 0) {
      return nullptr;
    } else if (nodes_lens >= 2) {
      /* 双指针 */
      int left_index = 0, right_index = 1;
      while (left_index < nodes_lens && right_index < nodes_lens) {
        /* 左指针++ */
        while (left_index < nodes_lens&& nodes[left_index] == nullptr) {
          left_index++;
          continue;
        }
        if (left_index >= nodes_lens) {
          break;
        }
        /* 右指针 */
        if (right_index + 1 < nodes_lens) {
          nodes[left_index]->left = nodes[right_index];
          nodes[left_index]->right = nodes[right_index + 1];
          right_index += 2;
        } else if (right_index + 1 == nodes_lens) {
          nodes[left_index]->left = nodes[right_index];
          right_index += 1; /* 最后一个了 */
        }
        left_index++;
      }
    }
    return nodes[0];
  }
};

int main(int argc, char const *argv[]) {

  // Codec ser, deser;
  // TreeNode *ans = deser.deserialize(ser.serialize(root));
  auto genTree = [](int x) {
    TreeNode *node = new TreeNode(x);
    return node;
  };
  auto root = genTree(1);
  root->left = genTree(2);
  root->right = genTree(3);
  root->right->left = genTree(4);
  root->right->right = genTree(5);

  Codec ser;
  // auto str1 = ser.serialize(root);
  // std::cout << str1 << std::endl;
  // auto root2 = ser.deserialize(str1);
  // str1 = ser.serialize(root2);
  // std::cout << str1 << std::endl;
  // str1 = ser.serialize(nullptr);
  // std::cout << str1 << std::endl;
  // str1 = ser.serialize(genTree(1));
  // std::cout << str1 << std::endl;

  auto root3 = ser.deserialize("[1,2,3,null,null,4,5]");
  /*
              1
        2           3
  null   null    4      5
              6     7
 */
  auto str1 = ser.serialize(root3);
  // root3->Print();
  std::cout << str1 << std::endl;
  return 0;
}
