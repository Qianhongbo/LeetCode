/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    backtrack(board, 0, 0);
  }

  bool backtrack(vector<vector<char>>& board, int r, int c) {
    int m = 9, n = 9;
    // arrive the last column
    if (c == n) {
      return backtrack(board, r + 1, 0);
    }

    // base case
    // arrive the last row
    if (r == m) {
      return true;
    }

    if (board[r][c] != '.') {
      return backtrack(board, r, c + 1);
    }

    for (char ch{'1'}; ch <= '9'; ch++) {
      if (!isValid(board, r, c, ch)) {
        continue;
      }

      board[r][c] = ch;

      if (backtrack(board, r, c + 1)) {
        return true;
      }

      board[r][c] = '.';
    }

    return false;
  }

  bool isValid(vector<vector<char>>& board, int r, int c, char aChar) {
    for (int i{0}; i < 9; i++) {
      if (board[r][i] == aChar) {
        return false;
      }
      if (board[i][c] == aChar) {
        return false;
      }
      if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == aChar) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
