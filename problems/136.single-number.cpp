/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// exclusive or 
// 0 0 : 0
// 0 1 : 1
// 1 0 : 1
// 1 1 : 0

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res{0};
    for (auto& n: nums) {
      res ^= n;
    }
    return res;
  }
};
// @lc code=end
