/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
 public:
  int countSubstrings(string s) {
    int res{0};
    for (int i{0}; i < s.size(); i++) {
      res += palindrome(s, i, i);
      res += palindrome(s, i, i + 1);
    }

    return res;
  }

  int palindrome(const string& s, int l, int r) {
    int res{0};
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      l--;
      r++;

      res++;
    }

    return res;
  }
};
// @lc code=end
