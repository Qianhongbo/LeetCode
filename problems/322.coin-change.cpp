/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include <vector>
#include <limits.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<int> memo;
  // top down
  int coinChange(vector<int>& coins, int amount) {
    memo.resize(amount + 1, -666);

    return dp(coins, amount);
  }

  int dp(vector<int>& coins, int amount) {
    if (0 == amount) {
      return 0;
    }

    if (amount < 0) {
      return -1;
    }

    if (memo[amount] != -666) {
      return memo[amount];
    }

    int res = INT_MAX;
    for (const auto& coin: coins) {
      int subProblem = dp(coins, amount - coin);
      if (-1 == subProblem) {
        continue;
      }

      res = min(res, subProblem + 1);
    }

    memo[amount] = res == INT_MAX ? -1 : res;

    return memo[amount];
  }

  // bottom up
  // int coinChange(vector<int>& coins, int amount) {
  //   // the reason why we use amout + 1 to initialize dp
  //   // is that the maximum value for us to change the coin is amount
  //   // which is all use one dollor coin
  //   // amount + 1 represents infinity
  //   // however we can't use INT_MAX because we also need to + 1 
  //   // this will cause integer overflow
  //   std::vector<int> dp(amount + 1, amount + 1);
  //   dp[0] = 0;
  //   for (int i{1}; i <= amount; i++) {
  //     for (const auto& coin : coins) {
  //       if (coin <= i) {
  //         dp[i] = std::min(dp[i], dp[i - coin] + 1);
  //       }
  //     }
  //   }
  //   return dp[amount] == amount + 1 ? -1 : dp[amount];
  // }
};
// @lc code=end
