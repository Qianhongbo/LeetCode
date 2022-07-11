/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
      // check the size first
      if (s.size() != t.size())
        return false;
      // check each character in two string
      std::unordered_map<char, int> theMap;
      for (auto& c : s) {
        theMap[c] += 1;
      }
      for (auto& c: t) {
        theMap[c] -= 1;
        if (theMap[c] < 0) {
          return false;
        }
      }
      return true;
    }
};
// @lc code=end

