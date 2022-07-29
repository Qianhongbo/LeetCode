/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 */

#include <climits>

// @lc code=start
class Solution {
 public:
  int preimageSizeFZF(int k) {
    // std::cout << trailingZeros(10e9) << "\n";
    // std::cout << trailingZeros(INT_MAX) << "\n";
    // std::cout << trailingZeros(LONG_MAX) << "\n";
    return static_cast<int>(findRightBount(k) - findLeftBount(k));
  }

  long trailingZeros(long k) {
    long res = 0;
    long tmp = 5;
    while (tmp <= k) {
      res += k / tmp;
      tmp *= 5;
    }

    return res;
  }

  long findLeftBount(int k) {
    long left = 0, right = LONG_MAX;
    while (left < right) {
      long mid = left + (right - left) / 2;

      if (trailingZeros(mid) == k) {
        right = mid;
      } else if (trailingZeros(mid) < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return right - 1;
  }

  long findRightBount(int k) {
    long left = 0, right = LONG_MAX;
    while (left < right) {
      long mid = left + (right - left) / 2;

      if (trailingZeros(mid) == k) {
        left = mid + 1;
      } else if (trailingZeros(mid) < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left - 1;
  }
};
// @lc code=end
