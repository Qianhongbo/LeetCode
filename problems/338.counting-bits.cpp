/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  // vector<int> countBits(int n) {
  //   std::vector<int> res;
  //   for (int i{0}; i <= n; i++) {
  //     int tmp{0};
  //     int theNum = i;
  //     while (theNum != 0) {
  //       theNum = theNum & (theNum - 1);
  //       tmp++;
  //     }

  //     res.push_back(tmp);
  //   }

  //   return res;
  // }
  // solution 2:
  vector<int> countBits(int n) {
    std::vector<int> res(n + 1, 0);
    for (int i{1}; i <= n; i++) {
      res[i] = res[i & i - 1] + 1;
    }

    return res;
  }
};
// @lc code=end
