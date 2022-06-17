/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> count; // map number to frequency
    int maxFreq = 1;
    for (const int& n : nums) {
      maxFreq = std::max(maxFreq, ++count[n]);
    }

    std::unordered_map<int, std::vector<int> > bucket;
    for (const auto& kv: count) {
      bucket[kv.second].push_back(kv.first);
    }

    std::vector<int> res;
    for (int i{maxFreq}; i > 0; i--) {
      res.insert(res.end(), bucket[i].begin(), bucket[i].end());
      if (res.size() == k) return res;
    }
    return res;
  }
};
// @lc code=end
