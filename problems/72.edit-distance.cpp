/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  // Top down
  std::vector<std::vector<int>> memo;

  int minDistance(string word1, string word2) {
    int l1 = word1.size();
    int l2 = word2.size();
    memo.resize(l1, std::vector<int>(l2, -1));
    return dp(word1, word2, l1 - 1, l2 - 1);
  }

  // definition: return the minDistance of [0, i] and [0, j]
  int dp(const string& word1, const string& word2, int i, int j) {
    if (-1 == i) {
      return j + 1;
    }

    if (-1 == j) {
      return i + 1;
    }

    if (-1 != memo[i][j]) {
      return memo[i][j];
    }

    if (word1[i] == word2[j]) {
      memo[i][j] = dp(word1, word2, i - 1, j - 1);
    } else {
      memo[i][j] = std::min({dp(word1, word2, i, j - 1) + 1,       // insert
                      dp(word1, word2, i - 1, j) + 1,       // delete
                      dp(word1, word2, i - 1, j - 1) + 1});  // replace
    }

    return memo[i][j];
  }

  // bottom up
  // int minDistance(string word1, string word2) {
  //   int m = word1.size(), n = word2.size();
  //   std::vector<std::vector<int>> dp;
  //   dp.resize(m + 1, std::vector<int>(n + 1, 0));
  //   for (int i{1}; i <= m; i++) {
  //     dp[i][0] = i;
  //   }
  //   for (int j{1}; j <= n; j++) {
  //     dp[0][j] = j;
  //   }
  //     for (int i{1}; i <= m; i++) {
  //       for (int j{1}; j <= n; j++) {
  //         if (word1[i - 1] == word2[j - 1]) {
  //           dp[i][j] = dp[i - 1][j - 1];
  //         } else {
  //           dp[i][j] = std::min({dp[i][j - 1] + 1,
  //                                dp[i - 1][j] + 1,
  //                                dp[i - 1][j - 1] + 1});
  //         }
  //       }
  //     }

  //   return dp[m][n];
  // }
};
// @lc code=end
