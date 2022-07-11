/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int rows;
  int cols;
  std::vector<std::pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  std::vector<std::vector<int>> visited;
  int res{0};

  const int SEA{0};
  const int LAND{1};
  int numEnclaves(vector<vector<int>>& grid) {
    if (0 == grid.size() || 0 == grid[0].size()) {
      return 0;
    }

    rows = grid.size();
    cols = grid[0].size();
    visited.resize(rows, std::vector<int>(cols, 0));

    // submerge islands on the border
    for (int r{0}; r < rows; r++) {
      dfs(grid, r, 0);
      dfs(grid, r, cols - 1);
    }

    for (int c{0}; c < cols; c++) {
      dfs(grid, 0, c);
      dfs(grid, rows - 1, c);
    }

    // check the number of islands within borders
    for (int r{1}; r < rows - 1; r++) {
      for (int c{1}; c < cols - 1; c++) {
        if (LAND == grid[r][c] && !visited[r][c]) {
          res++;
        }
      }
    }

    return res;
  }

  void dfs(vector<vector<int>>& grid, int r, int c) {
    if (!isInBound(r, c)) {
      return;
    }

    if (SEA == grid[r][c] || visited[r][c]) {
      return;
    }

    visited[r][c] = 1;

    for (const auto& [dr, dc] : directions) {
      dfs(grid, r + dr, c + dc);
    }
  }

  bool isInBound(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
      return false;
    }
    return true;
  }
};
// @lc code=end
