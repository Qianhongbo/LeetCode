/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
 public:
 // Time: O(n), Space: O(1)
  int lengthOfLongestSubstring(string s) {
    std::unordered_map<char, int> window;

    int left = 0, right = 0;
    int res = 0;
    while (right < s.size()) {
      char c = s[right];
      right++;
      // update the data in the sliding window
      window[c]++;

      while (window[c] > 1) {
        char d = s[left];
        left++;
        window[d]--;
      }
      res = std::max(res, right - left);
    }
    return res;
  }
};
// @lc code=end
