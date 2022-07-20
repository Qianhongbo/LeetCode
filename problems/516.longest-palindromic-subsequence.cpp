/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> memo;
  // bottom up
  int longestPalindromeSubseq(string s) {
    memo.resize(s.size(), std::vector<int>(s.size(), -1));
    return dp(s, 0, s.size() - 1);
  }

  // definition: the result of [i, j]
  int dp(const std::string& s, int i, int j) {
    // base case
    if (i > j) {
      return 0;
    }

    if (i == j) {
      return 1;
    }

    if (-1 != memo[i][j]) {
      return memo[i][j];
    }

    if (s[i] == s[j]) {
      memo[i][j] = dp(s, i + 1, j - 1) + 2;
    } else {
      memo[i][j] = std::max(dp(s, i + 1, j),
                      dp(s, i, j - 1));
    }

    return memo[i][j];
  }
};
// @lc code=end
