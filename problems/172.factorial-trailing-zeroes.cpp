/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
 public:
  int trailingZeroes(int n) {
    int res = 0;
    long tmp = 5;
    while (tmp <= n) {
      res += n / tmp;
      tmp *= 5;
    }
    
    return res;
  }
};
// @lc code=end
