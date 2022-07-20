/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sz = gas.size();
    int sum{0}, minSum{0};
    int start{0};
    for (int i{0}; i < sz; i++) {
      sum += gas[i] - cost[i];
      if (sum < minSum) {
        start = i + 1;
        minSum = sum;
      }
    }

    if (sum < 0) {
      return -1;
    }

    return start == sz ? 0 : start;
  }
};
// @lc code=end
