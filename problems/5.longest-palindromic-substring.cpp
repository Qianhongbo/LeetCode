/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
 public:
  int left;
  int right;
  string longestPalindrome(string s) {
    std::string res{""};
    for (int i{0}; i < s.size(); i++) {
      std::string s1 = palindrome(s, i, i);
      std::string s2 = palindrome(s, i, i + 1);

      res = res.size() > s1.size() ? res : s1;
      res = res.size() > s2.size() ? res : s2;
    }

    return res;
  }

  std::string palindrome(const string& s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      l--;
      r++;
    }

    return s.substr(l + 1, r - 1 - l - 1 + 1);
  }
};
// @lc code=end
