/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  Solution(vector<int>& w) {
    srand((unsigned)time(0)); // random number 
    prefixSum.push_back(0);
    for (const int& n : w) {
      prefixSum.push_back(prefixSum.back() + n);
    }
  }

  int pickIndex() {
    int theRand = rand() % prefixSum.back() + 1;  // [0, prefixSum(sz - 1)]
    // binary search
    int left = 0, right = prefixSum.size();
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (prefixSum[mid] == theRand) {
        right = mid;
      } else if (prefixSum[mid] < theRand) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left - 1;
  }

  private:
   std::vector<int> prefixSum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
