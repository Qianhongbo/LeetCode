/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

#include <string>
#include <utility>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
 public:
  
  std::unordered_map<char, int> window;

  string minWindow(string s, string t) {
    std::unordered_map<char, int> tMap;
    // transform the string t to a map
    for (const auto& c : t) {
      tMap[c]++;
    }

    int left = 0, right = 0;
    int valid = 0;
    int start = 0, len = INT_MAX;

    while (right < s.size()) {
      char c = s[right];
      right++;

      if (tMap.count(c)) {
        window[c]++;
        if (window[c] == tMap[c]) {
          valid++;
        }
      }

      while (valid == tMap.size()) {
        if (right - left < len) {
          start = left;
          len = right - left;
        }

        char d = s[left];
        left++;
        if (tMap.count(d)) {
          if (window[d] == tMap[d]) {
            valid--;
          }
          window[d]--;
        }
      }

    }

    return len == INT_MAX ? "" : s.substr(start, len);
  }

};
// @lc code=end
