/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include <queue>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int rows;
  int cols;
  std::vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  std::vector<std::vector<int>> visited;
  int count;

  const char LAND{'1'};
  const char WATER{'0'};

  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    rows = grid.size();
    cols = grid[0].size();
    // initialize the visited vector
    visited.resize(rows, std::vector<int>(cols, 0));

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (LAND == grid[r][c] && !visited[r][c]) {
          dfs(grid, r, c);
          // bfs(grid, r, c);
          count += 1;
        }
      }
    }
    return count;
  }

  void dfs(const std::vector<std::vector<char>>& grid, int r, int c) {
    if (!isInBound(r, c)) {
      return;
    }

    if (WATER == grid[r][c] || visited[r][c]) {
      return;
    }

    visited[r][c] = 1;
    for (const auto& [dr, dc] : directions) {
      dfs(grid, r + dr, c + dc);
    }
  }

  void bfs(const std::vector<std::vector<char>>& grid, int r, int c) {
    std::queue<std::pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;

    while (!q.empty()) {
      auto node = q.front();
      q.pop();

      for (const auto& [dr, dc] : directions) {
        int new_r = node.first + dr;
        int new_c = node.second + dc;

        if (!isInBound(new_r, new_c)) {
          continue;
        }

        if (WATER == grid[new_r][new_c] || visited[new_r][new_c]) {
          continue;
        }

        q.push({new_r, new_c});
        visited[new_r][new_c] = 1;
      }
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
