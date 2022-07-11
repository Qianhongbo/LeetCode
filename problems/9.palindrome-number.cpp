/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include <limits.h>

// @lc code=start
class Solution {
 public:
  // bool isPalindrome(int x) {
  // if (x < 0) {
  //   return false;
  // }

  //   int res{0};
  //   int theCopy{x};
  //   while (theCopy) {
  //     int pop = theCopy % 10;
  //     theCopy /= 10;
      
  //     if (res > INT_MAX / 10 || (INT_MAX / 10 == res && pop > 7)) {
  //       return false;
  //     }

  //     if (res < INT_MIN / 10 || (INT_MIN / 10 == res && pop < -8)) {
  //       return false;
  //     }

  //     res = res * 10 + pop;
  //   }

  //   return res == x;
  // }

  // a better solution? maybe too many conditions
  bool isPalindrome(int x) {
    if (x < 0 || (0 == x % 10 && x != 0)) {
      return false;
    }

    int reverse{0};
    while (x > reverse) {
      int pop = x % 10;
      reverse = reverse * 10 + pop;
      x /= 10;
    }

    return x == reverse || x == reverse / 10;
  }
};
// @lc code=end
