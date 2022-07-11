/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i{0};
    int j = numbers.size() - 1;
    while (i < j) {
      if (target == numbers[i] + numbers[j]) {
        break;
      } else if (target < numbers[i] + numbers[j]) {
        j--;
      } else {
        i++;
      }
    }
    return {i + 1, j + 1};
  }
};
// @lc code=end
