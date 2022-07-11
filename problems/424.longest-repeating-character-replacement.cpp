/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
 public:
  int characterReplacement(string s, int k) {
    std::unordered_map<char, int> window;
    int left = 0, right = 0;
    int theMax = 0;
    int res = 0;

    while (right < s.size()) {
      char c = s[right];
      window[c]++;
      right++;
      theMax = std::max(theMax, window[c]);

      while(right - left - theMax > k) {
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
