/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

#include <cstdint>

// @lc code=start
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int res{0};
    while (n != 0) {
      n = n & (n - 1);
      res++;
    }

    return res;
  }
};
// @lc code=end
