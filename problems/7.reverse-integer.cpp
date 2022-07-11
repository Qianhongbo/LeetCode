/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

#include <limits.h>  // ! important limits

// @lc code=start
class Solution {
 public:
  // Time: O(log(n)) Space: O(1)
  int reverse(int x) {
    int res{0};

    while (x) {
      int pop = x % 10;
      x /= 10;

      // ! const left principle
      if (res > INT_MAX / 10 || (INT_MAX / 10 == res && pop > 7)) {
        return 0;
      }

      if (res < INT_MIN / 10 || (INT_MIN / 10 == res && pop < -8)) {
        return 0;
      }

      res = res * 10 + pop;
    }

    return res;
  }
};
// @lc code=end
