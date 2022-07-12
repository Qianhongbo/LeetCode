/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    if (0 == n) {
      return {};
    }

    vector<string> res;

    std::string track;

    backtrack(n, n, track, res);

    return res;
  }

  void backtrack(int left, int right, std::string& track, vector<string>& res) {
    // the left should always <= right
    if (right < left) {
      return;
    }
    // if one number is less than zero, it is not legal
    if (left < 0 || right < 0) {
      return;
    }
    // if both are zero, we find the result
    if (left == 0 && right == 0) {
      res.push_back(track);
      return;
    }
    // try to add a left paren
    track.push_back('(');
    backtrack(left - 1, right, track, res);
    track.pop_back();
    // try to add a right paren
    track.push_back(')');
    backtrack(left, right - 1, track, res);
    track.pop_back();
  }
};
// @lc code=end
