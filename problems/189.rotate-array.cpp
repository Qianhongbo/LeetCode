/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

#include <vector>
#include <algorithm>
using namespace std;

// 1 2 3 4 5 6     k = 3
// 3 2 1 6 5 4
// 4 5 6 1 2 3

// @lc code=start
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    
    int sz = nums.size();
    // first reverse the first k number
    k = k % sz;
    reverse(nums, 0, sz - k - 1);
    // seconde reverse the rest
    reverse(nums, sz - k, sz - 1);
    // reverse all
    reverse(nums, 0, sz - 1);
  }

  void reverse(vector<int>& nums, int i, int j) {
    while (i < j) {
      // swap
      nums[i] ^= nums[j];
      nums[j] ^= nums[i];
      nums[i] ^= nums[j];
      i++;
      j--;
    }
  }
};
// @lc code=end
