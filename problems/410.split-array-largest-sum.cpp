/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    int left = 0, right = 0;
    for (const auto& n : nums) {
      left = std::max(left, n);
      right += n;
    }

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (split(nums, mid) == m) {
        right = mid;
      } else if (split(nums, mid) > m) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }

  int split(const vector<int>& nums, int sum) {
    int res = 0;
    int tmp = 0;
    for (const int& n : nums) {
      tmp += n;
      if (tmp == sum) {
        res++;
        tmp = 0;
      } else if (tmp > sum) {
        res++;
        tmp = n;
      }
    }

    if (tmp != 0) {
      res++;
    }
    return res;
  }
};
// @lc code=end
