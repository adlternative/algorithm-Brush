#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#define SPDLOG_FMT_EXTERNAL
#include <spdlog/spdlog.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
class Solution {
public:
  string removeDuplicateLetters(string s) {
    string ret;
    deque<int> deq;
    unordered_set<char> in_deq;
    unordered_map<char, int> count_maps;
    auto len = s.size();

    for (auto &&c : s) {
      auto iter = count_maps.find(c);
      if (iter == count_maps.end())
        count_maps.emplace(c, 1);
      else
        iter->second++;
    }

    for (int i = 0; i < len; i++) {
      if (i == 0) {
        in_deq.insert(s[i]);
        deq.push_back(i);
        count_maps[s[i]]--;
        // if (count_maps[s[i]])
        continue;
      } else {
        /* 栈里找到了则不换 */
        if (in_deq.find(s[i]) != in_deq.end()) {
          count_maps[s[i]]--;
          continue;
        }
        /* 比栈顶大, 加入并 继续*/
        if (s[i] > s[deq.back()]) {
          goto here;
          continue;
        }

        /* 比栈顶小, 换*/
        while (!deq.empty() && s[i] < s[deq.back()]) {
          /* 如果字典上还有该字符则可以换 */
          auto top = s[deq.back()];
          if (count_maps[top]) {
            in_deq.erase(top);
            deq.pop_back();
          } else {
            break;
          }
        }
      here: /* 无论是比栈顶大还是把栈换了几个，我们都得把它入栈 */
        deq.push_back(i);
        in_deq.insert(s[i]);
        count_maps[s[i]]--;
      }
    }
    for (auto c : deq)
      ret.push_back(s[c]);
    return std::move(ret);
  }
};
int main(int argc, char const *argv[]) {
  spdlog::set_level(spdlog::level::debug);
  Solution s;
  string str /*  = "cbacdcbc" */;
  string ret /*  = s.removeDuplicateLetters(str) */;
  str = "peymrzknlxtrutjiybqemquchgvtmmtpjvunvekszrkatctcirxwuqknrycpdtcuadblzk"
        "kleduezgspoxhhssoipbmdgrqggpfdsanolzczpaggwxrlaleaqtnzxclmxwjucnujsptn"
        "bmmjzzjhypnlsoxjveywsufegzlfnyvkcnfevkshbckfropoydkdlblppllgefagjgpajs"
        "plvxknvtlgtjyhmnwxcpjjzcizihycvsnhnnmqohivekitxzuo";
  ret = s.removeDuplicateLetters(str);
  std::cout << ret << std::endl;
  return 0;
}
