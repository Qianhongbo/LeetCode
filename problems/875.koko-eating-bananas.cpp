/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    // binary search
    int left = 1, right = INT_MAX;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (totalTime(piles, mid) == h) {
        right = mid;
      } else if (totalTime(piles, mid) > h) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }

  int totalTime(vector<int>& piles, int speed) {
    int theTime = 0;

    for (const auto& pile: piles) {
      theTime += pile / speed;
      if (0 != pile % speed) {
        theTime++;
      }
    }

    return theTime;
  }
};
// @lc code=end
