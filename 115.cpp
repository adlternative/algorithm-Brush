#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    size_t len1 = s.size();
    size_t len2 = t.size();
    if (len1 < len2 || s.empty() || t.empty())
      return 0;
    long long dp[len1 + 1][len2 + 1];

    for (size_t j = 0; j < len2 + 1; j++) {
      dp[0][j] = 0;
    }
    for (size_t i = 0; i < len1 + 1; i++) {
      dp[i][0] = 1;
    }
    for (size_t i = 1; i < len1 + 1; i++) {
      for (size_t j = 1; j < len2 + 1; j++) {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        /* aa[b]xxx a[b]xxxx 也就是aa加上b 匹配ab 的量是原有的 aa<->a  2 +
         * 之前aa匹配 ab的数量 0*/
        else
          dp[i][j] = dp[i - 1][j];
      }
    }

    return dp[len1][len2];
  }

  /*
   * if s == "rabbbit" t="rabbit"
   * then if we choose r a b b b, failed
   * so let's record that the t[4] can't choose s[4]   (4,4)  t s
   * and then r a b b i t ok! cnt++;  4 5 ok
   * 4 6 ...
   * so it's a memory-search
   */
  // int **map_;
  // int cnt = 0;
  // size_t len1;
  // size_t len2;
  // string s_;
  // string t_;
  // int numDistinct(string s, string t) {
  //   if (s.size() < t.size() || s.empty() || t.empty())
  //     return cnt;
  //   s_ = std::move(s);
  //   t_ = std::move(t);
  //   size_t beginTIndex = 0;
  //   len1 = s_.size();
  //   len2 = t_.size();
  //   map_ = new int *[len1];
  //   for (size_t i = 0; i < len1; i++) {
  //     map_[i] = new int[len2];
  //   }
  //   for (size_t i = 0; i < len1; i++) {
  //     for (size_t j = 0; j < len2; j++) {
  //       map_[i][j] = 0;
  //     }
  //   }

  //   /* 0-1 */
  //   for (size_t beginSIndex = 0; beginSIndex <= len1 - len2; beginSIndex++) {
  //     dfs(beginSIndex, beginTIndex);
  //   }
  //   for (size_t i = 0; i < len1; i++) {
  //     delete[] map_[i];
  //   }
  //   delete[] map_;
  //   return cnt;
  // }
  // /* 匹配到s第si位，t的第ti位 0 0 开始 */
  // int dfs(int si, int ti) {

  //   // if (ti == len2) {
  //   //   cnt++;
  //   //   return 1;
  //   // }

  //   if (map_[si][ti] < 0) {
  //     return 0;
  //   } else if (map_[si][ti] == 0) {
  //     if (s_[si] != t_[ti]) {
  //       map_[si][ti] = -1;
  //       // std::cout << "not" << si << ti << std::endl;
  //       return 0;
  //     }
  //     int okCnt = 0;
  //     if (ti + 1 == len2) {
  //       cnt++;
  //       okCnt++;
  //       map_[si][ti] = okCnt;
  //       return okCnt;
  //     }
  //     for (size_t i = si + 1; i < len1; i++) {
  //       // std::cout << i << ti << std::endl;
  //       okCnt += dfs(i, ti + 1);
  //     }

  //     map_[si][ti] = okCnt;
  //     return okCnt;
  //   } else {
  //     cnt += map_[si][ti];
  //     return map_[si][ti];
  //   }
  // }
};

int main(int argc, char const *argv[]) {
  Solution s;
  // int cnt = s.numDistinct(
  //     "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeu"
  //     "qnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqk"
  //     "pabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggl"
  //     "eiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsz"
  //     "tuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneeh"
  //     "dwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykg"
  //     "scxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsx"
  //     "zylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhj"
  //     "cslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwy"
  //     "iglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjx"
  //     "vhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvef"
  //     "ugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlc"
  //     "ntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaie"
  //     "hlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo",
  //     "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys");
  // int cnt = s.numDistinct("rabbbit", "rabbit");
  int cnt = s.numDistinct("babgbag", "bag");
  std::cout << cnt << std::endl;
  return 0;
  /*

  "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys"
   */
}
