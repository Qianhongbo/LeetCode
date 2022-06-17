/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int rows;
  int cols;
  std::vector<std::pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  std::vector<std::vector<int>> visited;  // color
  const int LAND{1};
  const int WATER{0};
  int color{0};
  std::map<int, int> map{ {0, 0} };

  int largestIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    rows = grid.size();
    cols = grid[0].size();
    visited.resize(rows, std::vector<int>(cols, 0));

    // first get the max area
    int maxArea{0};
    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (LAND == grid[r][c] && !visited[r][c]) {
          color++;
          int area = dfs(grid, r, c);
          map[color] = area;
          maxArea = std::max(maxArea, area);
        }
      }
    }

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (WATER == grid[r][c]) {
          int area{1};
          std::set<int> colorSet;
          for (const auto& [dr, dc] : directions) {
            colorSet.insert(getColor(r + dr, c + dc));
          }

          for (const int& c: colorSet) {
            area += map[c];
          }

          maxArea = std::max(maxArea, area);
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

    visited[r][c] = color;
    int area{1};
    for (const auto& [dr, dc] : directions) {
      area += dfs(grid, r + dr, c + dc);
    }
    return area;
  }

  bool isInBound(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
      return false;
    }
    return true;
  }

  int getColor(int r, int c) {
    if (!isInBound(r, c)) {
      return 0;
    }
    return visited[r][c];
  }
};
// @lc code=end
