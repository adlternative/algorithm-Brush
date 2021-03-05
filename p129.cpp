//
// Created by adl on 2020/10/29.
//
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//
//class Solution {
//    int sum;
//    vector<TreeNode *> s;
//public:
//    Solution() : sum(0) {}
//
//    int sumNumbers(TreeNode *root) {
//        if(!root){
//            return sum;
//        }
//        s.push_back(root);
//        while(!s.empty()) {
//            auto cur =s[s.size()-1];
//            while (cur) {
//                s.push_back(cur);
//                cur = cur->left;
//            }
//            /*495*/
//            auto t = s[s.size()-1];
//            if (t->right) {
//                cur=t->right;
//                continue;
//            } else {
//                string ss(s.begin(),s.end());
//                sum+=stoi(ss);
//                s.pop_back();
//            }
//        }
//        return sum;
//    }
//
//};
class Solution {
    int sum;
public:
    Solution() : sum(0) {}

    vector<int> v;
public:
    int sumNumbers(TreeNode *root) {
        if (root) {
            v.push_back(root->val);
            if (!root->left && !root->right) {
//                string ss(v.begin(), v.end());
//                sum += stoi(ss);
                //v.size()=3 495

                for (int i = 0; i != v.size(); ++i) {
                    sum += v[i]*pow(10, v.size() - 1 - i);
                }
//                std::cout << sum << std::endl;

                v.pop_back();
                return sum;
            }
            if (root->left)
                sumNumbers(root->left);
            if (root->right)
                sumNumbers(root->right);
            v.pop_back();
            return sum;
        }
        return 0;
    }
};

int main(int argc, char *argv[]) {
//    TreeNode*A =new TreeNode(4) ;
    TreeNode*A2 =new TreeNode(9) ;
//    TreeNode*A3 =new TreeNode(0) ;
//    TreeNode*A4 =new TreeNode(5) ;
//    TreeNode*A5 =new TreeNode(1) ;
//    A->left=A2;
//    A2->left=A4;
//    A2->right=A5;
//    A->right=A3;

    Solution s;
    int cnt=s.sumNumbers(A2);
    std::cout << cnt << std::endl;

    return 0;
}