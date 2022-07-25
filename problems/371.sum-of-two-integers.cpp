/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

#include <limits.h>
#include <cstdint>

// @lc code=start
class Solution {
 public:
  int getSum(int a, int b) {
    // long mask = 0xFFFFFFFF;

    while (b != 0) {
      int answer = (a ^ b);
      int carry = static_cast<uint32_t>((a & b)) << 1;
      a = answer;
      b = carry;
    }

    return a;
  }
};
// @lc code=end
