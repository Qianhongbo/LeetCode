/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
 public:
  int rows;
  int cols;
  std::vector<std::pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // ! pair need to include utility
  std::vector<std::vector<int>> visited;
  int LAND{1};
  int WATER{0};

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    rows = grid.size();
    cols = grid[0].size();

    visited.resize(rows, std::vector<int>(cols, 0));

    int maxArea{0};
    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (LAND == grid[r][c] && !visited[r][c]) {
          // int area = dfs(grid, r, c);
          int area = bfs(grid, r, c);
          maxArea = std::max(maxArea, area); // ! need to include algorithm
        }
      }
    }
    return maxArea;
  }
  
  int dfs(vector<vector<int>>& grid, int r, int c) {
    if (!isInBound(r, c)) {
      return 0;
    }

    if (WATER == grid[r][c] || visited[r][c]) {
      return 0;
    }

    visited[r][c] = 1;
    int area{1};
    for (const auto& [dr, dc] : directions) {
      area += dfs(grid, r + dr, c + dc);
    }
    return area;
  }

  int bfs(vector<vector<int>>& grid, int r, int c) {
    std::queue<std::pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;

    int area{1};
    while (!q.empty()) {
      // get the front element in queue
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
        area++;
      }
    }
    return area;
  }

  bool isInBound(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
      return false;
    }
    return true;
  }
};
// @lc code=end
