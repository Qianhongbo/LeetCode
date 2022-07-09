/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int res{0};
    int rows = grid.size();
    int cols = grid[0].size();

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        // if we find the land
        if (grid[r][c]) {
          // add four because one square has four lines
          res += 4;
          // if left exists, minus 4
          if (r > 0 && grid[r - 1][c]) {
            res -= 2;
          }
          // if left exists, minus 4
          if (c > 0 && grid[r][c - 1]) {
            res -= 2;
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
