/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    int rows = n, cols = n;
    std::vector<std::vector<int>> res;
    res.resize(rows, std::vector<int>(cols, 0));

    int upperBound = 0, lowerBound = rows - 1;
    int leftBound = 0, rightBound = cols - 1;
    int temp = 1;
    while (temp <= n * n) {
      if (upperBound <= lowerBound) {
        for (int c{leftBound}; c <= rightBound; c++) {
          res[upperBound][c] = temp++;
        }
        upperBound++;
      }

      if (leftBound <= rightBound) {
        for (int r{upperBound}; r <= lowerBound; r++) {
          res[r][rightBound] = temp++;
        }
        rightBound--;
      }

      if (upperBound <= lowerBound) {
        for (int c{rightBound}; c >= leftBound; c--) {
          res[lowerBound][c] = temp++;
        }
        lowerBound--;
      }

      if (leftBound <= rightBound) {
        for (int r{lowerBound}; r >= upperBound; r--) {
          res[r][leftBound] = temp++;
        }
        leftBound++;
      }
    }

    return res;
  }
};
// @lc code=end
