/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    std::unordered_map<int, int> mp{{0, 1}};
    int sum{0};
    int res{0};
    for (const auto& n: nums) {
      sum += n;
      int temp = sum - k;
      res += mp[temp];
      mp[sum]++;
    }

    return res;
  }
};
// @lc code=end
