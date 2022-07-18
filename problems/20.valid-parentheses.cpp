/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> st;
    // ! the order should be reversed
    std::unordered_map<char, char> mp{{')', '('}, {']', '['}, {'}', '{'}};

    for (const char c : s) {
      if ('(' == c || '{' == c || '[' == c) {
        st.push(c);
      } else {
        if (!st.empty() && st.top() == mp[c]) {
          st.pop();
        } else {
          return false;
        }
      }
    }

    return st.empty(); // ! important because '('
  }
};
// @lc code=end
