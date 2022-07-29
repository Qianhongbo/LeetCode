/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

#include <vector>
using namespace std;

/*

1 2 3 3 4 5 
less or equal:
1 2 3 4 5 6
      |
t t t f f f
the first number that the count is greater than the value
this array has monotonicity, we can use binary search
*/

// @lc code=start
class Solution {
 public:
  //binary search 
  int findDuplicate(vector<int>& nums) {
    int left{1}, right = nums.size();

    auto lessOrEqual = [&](int mid) {
      int theCount{0};
      for (const int& n : nums) {
        if (n <= mid) {
          theCount++;
        }
      }
      return theCount;
    };

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (lessOrEqual(mid) > mid) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return right + 1;
  }
};
// @lc code=end
