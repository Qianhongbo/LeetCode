/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

#include <set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  // ? The first solution
  // * Time: O(N^2), Space: O(N^2) where N is the size of the board
  // * Actually, if the size of the board is fixed, the complexity should be O(1)
  // Using hashset for row, column and 3x3 box
  // bool isValidSudoku(vector<vector<char>>& board) {
  //   int theSize = 9;
  //   // initialize vector of set
  //   std::vector<set<char>> rows;
  //   std::vector<set<char>> cols;
  //   std::vector<set<char>> boxes;
  //   // putback sets to the vector
  //   for (int i{0}; i < theSize; i++) {
  //     rows.push_back({});
  //     cols.push_back({});
  //     boxes.push_back({});
  //   }
  //   for (int r{0}; r < theSize; r++) {
  //     for (int c{0}; c < theSize; c++) {
  //       char theChar = board[r][c];

  //       if ('.' == theChar) {
  //         continue;
  //       }

  //       if (rows[r].count(theChar)) {
  //         return false;
  //       }
  //       rows[r].insert(theChar);

  //       if (cols[c].count(theChar)) {
  //         return false;
  //       }
  //       cols[c].insert(theChar);

  //       int idx = (r / 3) * 3 + (c / 3);
  //       if (boxes[idx].count(theChar)) {
  //         return false;
  //       }
  //       boxes[idx].insert(theChar);
  //     }
  //   }

  //   return true;
  // }

  // ? The second solution
  // use bit to represent different position rather than a set
  // * Time: O(N^2), Space: O(N) where N is the size of the board
  bool isValidSudoku(vector<vector<char>>& board) {
    int theSize = 9;
    // initialize three vectors of integers
    std::vector<int> rows(theSize, 0);
    std::vector<int> cols(theSize, 0);
    std::vector<int> boxes(theSize, 0);

    for (int r{0}; r < theSize; r++) {
      for (int c{0}; c < theSize; c++) {
        char theChar = board[r][c];

        if ('.' == theChar) {
          continue;
        }

        // change the char to integer
        size_t theValue = theChar - '0';  // ! must use size_t, because we can't shift an negative value
        int pos = 1 << (theValue - 1);    // ! An important step

        if ((rows[r] & pos) > 0) {
          return false;
        }
        rows[r] |= pos;

        // Check the column
        if ((cols[c] & pos) > 0) {
          return false;
        }
        cols[c] |= pos;

        // Check the box
        int idx = (r / 3) * 3 + c / 3;
        if ((boxes[idx] & pos) > 0) {
          return false;
        }
        boxes[idx] |= pos;
      }
    }

    return true;
  }
};
// @lc code=end
