/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<int> memo;
  // top down
  int climbStairs(int n) {
    memo.resize(n + 1, -1);
    return dp(n);
  }

  // definition: the result of n steps
  int dp(const int& n) {
    if (n <= 2) {
      return n;
    }

    if (-1 != memo[n]) {
      return memo[n];
    }

    memo[n] = dp(n - 1) + dp(n - 2);

    return memo[n];
  }
};
// @lc code=end
