/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
 public:
  //  // Time : O(n) | Space : O(n)
  //   bool isPalindrome(string s) {
  //     std::string theFilteredStr;
  //     for (const char& c: s) {
  //       if (std::isalnum(c)) {
  //         theFilteredStr += std::tolower(c);
  //       }
  //     }

  //     std::string theReverseStr;
  //     theReverseStr.resize(theFilteredStr.size());
  //     reverse_copy(theFilteredStr.begin(), theFilteredStr.end(), theReverseStr.begin());
  //     return theReverseStr == theFilteredStr;
  //   }

  // // Time : O(n) | Space : O(n)
  // bool isPalindrome(string s) {
  //   std::string theFilteredStr;
  //   for (const char& c : s) {
  //     if (std::isalnum(c)) {
  //       theFilteredStr += std::tolower(c);
  //     }
  //   }

  //   auto left = theFilteredStr.begin();
  //   auto right = theFilteredStr.end() - 1;
  //   while (left <= right) {
  //     if (*left != *right) return false;
  //     left++;
  //     right--;
  //   }
  //   return true;
  // }

  // Time : O(n) | Space : O(1)
  bool isPalindrome(string s) {
    int i{0};
    int j{static_cast<int>(s.size() - 1)};
    for (; i < j; i++, j--) {
      while (i < j && !isalnum(s[i])) {
        i++;
      }

      while (i < j && !isalnum(s[j])) {
        j--;
      }

      if (std::tolower(s[i]) != std::tolower(s[j])) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
