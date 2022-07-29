/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

#include <vector>
using namespace std;

/*

1 2 
3 4


1 3
2 4

idx  0 1
     3 1
     4 2

*/

// @lc code=start
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int r{0}; r < rows; r++) {
      for (int c{r + 1}; c < cols; c++) {
        // swap the number in a diagonal position
        int tmp = matrix[r][c];
        matrix[r][c] = matrix[c][r];
        matrix[c][r] = tmp;
      }
    }

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols / 2; c++) {
        int tmp = matrix[r][c];
        matrix[r][c] = matrix[r][cols - 1 - c];
        matrix[r][cols - 1 - c] = tmp;
      }
    }
  }
};
// @lc code=end
