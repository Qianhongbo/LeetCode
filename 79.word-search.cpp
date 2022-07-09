/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

#include <string>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int rows;
  int cols;
  std::vector<std::pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  std::vector<std::vector<bool>> memo;

  bool exist(vector<vector<char>>& board, string word) {
    rows = board.size();
    cols = board[0].size();

    memo.resize(rows, std::vector<bool>(cols, false));

    for (int i{0}; i < rows; i++) {
      for (int j{0}; j < cols; j++) {
        if (backtrack(board, word, 0, i, j)) {
          return true;
        }
      }
    }
    return false;
  }

  bool backtrack(const vector<vector<char>>& board,
                 const string& word,
                 int d,
                 int r,
                 int c) {
    // if out of bound
    // if we have visited
    // if the word is not as expected
    // just return
    if (!isInBound(r, c) || memo[r][c] || word[d] != board[r][c]) {
      return false;
    }

    // found the last char of the word
    if (d == word.size() - 1) {
      return true;
    }

    memo[r][c] = true;

    bool res{false};
    for (const auto& [dr, dc] : directions) {
      res |= backtrack(board, word, d + 1, r + dr, c + dc);
    }

    memo[r][c] = false;

    return res;
  }

  bool isInBound(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
      return false;
    }
    return true;
  }
};
// @lc code=end
