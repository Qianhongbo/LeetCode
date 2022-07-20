/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  // std::vector<int> memo;

  // int numDecodings(string s) {
  //   memo.resize(s.size(), 0);
  //   return dp(s, 0);
  // }

  // int dp(const std::string& s, int start) {
  //   if (start == s.size()) {
  //     return 1;
  //   }

  //   if ('0' == s[start]) {
  //     return 0;
  //   }

  //   if (s.size() - 1 == start) {
  //     return 1;
  //   }

  //   if (0 != memo[start]) {
  //     return memo[start];
  //   }

  //   if ('1' <= s[start] && s[start] <= '9') {
  //     memo[start] += dp(s, start + 1);
  //   }

  //   if ('1' == s[start] || '2' == s[start] && s[start + 1] <= '6') {
  //     memo[start] += dp(s, start + 2);
  //   }

  //   return memo[start];
  // }

  // bottom up
  int numDecodings(string s) {
    int sz = s.size();
    if (sz == 0) {
      return 0;
    }

    std::vector<int> dp(sz + 1, 0);
    dp[0] = 1;
    dp[1] = '0' == s[0] ? 0 : 1;

    for (int i{2}; i <= sz; i++) {
      char c = s[i - 1], d = s[i - 2];
      if ('1' <= c && c <= '9') {
        dp[i] += dp[i - 1];
      }

      if (d == '1' || d == '2' && c <= '6') {
        dp[i] += dp[i - 2];
      }
    }

    return dp[sz];
  }
};
// @lc code=end
