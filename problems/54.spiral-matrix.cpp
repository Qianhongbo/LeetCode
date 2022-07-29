/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int upperBound = 0, lowerBound = rows - 1;
    int leftBound = 0, rightBound = cols - 1;
    std::vector<int> res;
    while (res.size() < rows * cols) {
      if (upperBound <= lowerBound) {
        for (int c{leftBound}; c <= rightBound; c++) {
          res.push_back(matrix[upperBound][c]);
        }
        upperBound++;
      }

      if (leftBound <= rightBound) {
        for (int r{upperBound}; r <= lowerBound; r++) {
          res.push_back(matrix[r][rightBound]);
        }
        rightBound--;
      }

      if (upperBound <= lowerBound) {
        for (int c{rightBound}; c >= leftBound; c--) {
          res.push_back(matrix[lowerBound][c]);
        }
        lowerBound--;
      }

      if (leftBound <= rightBound) {
        for (int r{lowerBound}; r >= upperBound; r--) {
          res.push_back(matrix[r][leftBound]);
        }
        leftBound++;
      }
    }

    return res;
  }
};
// @lc code=end
