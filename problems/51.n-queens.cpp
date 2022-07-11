/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<string>> res;

  vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);
    return res;
  }

  void backtrack(vector<string>& board, int r) {
    if (r == board.size()) {
      res.push_back(board);
      return;
    }

    int cols = board[r].size();
    for (int c{0}; c < cols; c++) {
      if (!isValid(board, r, c)) {
        continue;
      }

      board[r][c] = 'Q';
      backtrack(board, r + 1);
      board[r][c] = '.';
    }
  }

  bool isValid(const vector<string>& board, int r, int c) {
    int cols = board.size();

    // check upper
    for (int i{0}; i < r; i++) {
      if (board[i][c] == 'Q') {
        return false;
      }
    }

    // check upper left
    for (int i{r - 1}, j{c - 1}; i >=0 && j >=0; i--, j--) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
      
    // check upper right
    for (int i{r - 1}, j{c + 1}; i >=0 && j < cols; i--, j++) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
