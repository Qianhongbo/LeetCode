/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

using namspace std;

// @lc code=start
class Solution {
 public:
  int fib(int n) {
    if ( n == 0 || n == 1) {
      return n;
    }

    int dp_1 = 0;
    int dp_2 = 1;
    for (int i{1}; i < n; i++) {
      int temp = dp_1 + dp_2;
      dp_1 = dp_2;
      dp_2 = temp;
    }

    return dp_2;
  }
};
// @lc code=end
