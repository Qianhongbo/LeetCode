/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  // time: O(m*n) space: O(m+n)
  // void setZeroes(vector<vector<int>>& matrix) {
  //   int rows = matrix.size(), cols = matrix[0].size();
  //   std::unordered_set<int> theRowSet;
  //   std::unordered_set<int> theColSet;
  //   for (int r{0}; r < rows; r++) {
  //     for (int c{0}; c < cols; c++) {
  //       if (0 == matrix[r][c]) {
  //         // we find zero
  //         theRowSet.insert(r);
  //         theColSet.insert(c);
  //       }
  //     }
  //   }
  //   for (int r{0}; r < rows; r++) {
  //     for (int c{0}; c < cols; c++) {
  //       if (theRowSet.count(r) || theColSet.count(c)) {
  //         matrix[r][c] = 0;
  //       }
  //     }
  //   }
  // }

  // time: O(m*n) space: O(1)
  void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    bool isCol{false};

    // use the first row and col as the set in the first solution
    for (int r{0}; r < rows; r++) {
      if (0 == matrix[r][0]) {
        isCol = true;
      }
      for (int c{1}; c < cols; c++) {
        if (0 == matrix[r][c]) {
          matrix[0][c] = 0;
          matrix[r][0] = 0;
        }
      }
    }

    // set the matrix except the first row and the first column
    for (int r{1}; r < rows; r++) {
      for (int c{1}; c < cols; c++) {
        if (0 == matrix[r][0] || 0 == matrix[0][c]) {
          matrix[r][c] = 0;
        }
      }
    }

    // check whether need to set the first row as zero
    if (0 == matrix[0][0]) {
      for (int c{0}; c < cols; c++) {
        matrix[0][c] = 0;
      }
    }

    // check whether need to set the first col as zero
    if (isCol) {
      for (int r{0}; r < rows; r++) {
        matrix[r][0] = 0;
      }
    }
  }
};
// @lc code=end
