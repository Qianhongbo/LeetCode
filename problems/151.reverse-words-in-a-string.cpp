/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

#include <sstream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    std::string res;
    std::string tmp;
    std::stringstream ss(s);
    while (ss >> tmp) {
      res += tmp;
      res += ' ';
    }

    res = res.substr(0, res.size() - 1);  // erase the last white space

    int sz = res.size();
    reverse(res, 0, sz - 1);

    for (int i{0}; i < sz;) {
      for (int j{i}; j < sz; j++) {
        if (j + 1 == sz || res[j + 1] == ' ') {
          reverse(res, i, j);
          i = j + 2;
          break;
        }
      }
    }

    return res;
  }

  void reverse(std::string& aStr, int i, int j) {
    while (i < j) {
      char tmp = aStr[i];
      aStr[i] = aStr[j];
      aStr[j] = tmp;
      i++;
      j--;
    }
  }
};
// @lc code=end
