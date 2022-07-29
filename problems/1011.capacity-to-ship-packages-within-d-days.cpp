/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int days) {
    // binary search
    int left = 0, right = 1;

    for (const auto& w: weights) {
      left = std::max(left, w);
      right += w;
    }

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (countDays(weights, mid) == days) {
        right = mid;
      } else if (countDays(weights, mid) > days) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }

  int countDays(const vector<int>& weights, int capacity) {
    int res = 0;
    int tmp = 0;
    for (const auto& w : weights) {
      tmp += w;
      if (tmp == capacity) {
        res++;
        tmp = 0;
      } else if (tmp > capacity) {
        res++;
        tmp = w;
      }
    }
    if (0 != tmp) res++;
    return res;
  }
};
// @lc code=end
