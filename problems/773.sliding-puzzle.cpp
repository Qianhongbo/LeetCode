/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

/*

3 2 1 
5 4 0

3 2 1 5 4 0
0 1 2 3 4 5



*/

// @lc code=start
class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    int m{2}, n{3};
    std::string target{"123450"};

    std::string start;
    for (int r{0}; r < m; r++) {
      for (int c{0}; c < n; c++) {
        start += std::to_string(board[r][c]);
      }
    }

    std::vector<std::vector<int>> neighbor{{1, 3},
                                           {0, 4, 2},
                                           {1, 5},
                                           {0, 4},
                                           {1, 3, 5},
                                           {2, 4}};
    std::queue<std::string> q;
    std::set<std::string> visited;

    q.push(start);
    visited.insert(start);

    int step{0};
    while(!q.empty()) {
      int sz = q.size();
      for (int i{0}; i < sz; i++) {
        std::string curr = q.front();
        q.pop();
        if (curr == target) {
          return step;
        }
        // find the index of 0
        int idx{0};
        while ('0' != curr[idx]) {
          idx++;
        }
        // exchange zero with other numbers
        for (const auto& adj: neighbor[idx]) {
          std::string theNewStr = swap(curr, adj, idx);
          if (!visited.count(theNewStr)) {
            q.push(theNewStr);
            visited.insert(theNewStr);
          }
        }
      }
      step++;
    }
    return -1;
  }

  std::string swap(const std::string& aStr, int i, int j) {
    std::string tmp(aStr);
    char c = tmp[i];
    tmp[i] = tmp[j];
    tmp[j] = c;
    return tmp;
  }
};
// @lc code=end
