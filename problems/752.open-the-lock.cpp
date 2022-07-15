/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

#include <vector>
#include <set>
#include <queue>
#include <string>
using namespace std;

// @lc code=start
class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    std::set<std::string> dead;
    for (const auto& str: deadends) {
      dead.insert(str);
    }
    std::set<std::string> visited;
    std::queue<std::string> q;
    int step{0};
    q.push("0000");
    visited.insert("0000");

    while (!q.empty()) {
      int sz = q.size();
      for (int i{0}; i < sz; i++) {
        std::string curr = q.front();
        q.pop();

        if (dead.count(curr)) {
          continue;
        }
        if (curr == target) {
          return step;
        }

        for (int j{0}; j < 4; j++) {
          std::string tmp1(curr);
          tmp1[j] = '0' + (tmp1[j] - '0' + 1) % 10;
          if (!visited.count(tmp1)) {
            q.push(tmp1);
            visited.insert(tmp1);
          }

          std::string tmp2(curr);
          tmp2[j] = '0' + (tmp2[j] - '0' - 1 + 10) % 10;
          if (!visited.count(tmp2)) {
            q.push(tmp2);
            visited.insert(tmp2);
          }
        }
      }
      step++;
    }
    return -1;
  }
};
// @lc code=end
