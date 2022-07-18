/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  // top down
  // int fib(int n) {
  //   if (n == 0 || n == 1) {
  //     return n;
  //   }
  //   return fib(n - 1) + fib(n - 2);
  // }
  
  // using memo
  int fib(int n) {
    std::vector<int> memo(n + 1, -1);
    return helper(memo, n);
  }

  int helper(std::vector<int>& memo, int n) {
    if (n == 0 || n == 1) {
      return n;
    }

    if (-1 != memo[n]) {
      return memo[n];
    }

    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    return memo[n];
  }

  // bottom up
  // int fib(int n) {
  //   if (n == 0 || n == 1) {
  //     return n;
  //   }

  //   int dp_1 = 0;
  //   int dp_2 = 1;
  //   for (int i{1}; i < n; i++) {
  //     int temp = dp_1 + dp_2;
  //     dp_1 = dp_2;
  //     dp_2 = temp;
  //   }

  //   return dp_2;
  // }
};
// @lc code=end
