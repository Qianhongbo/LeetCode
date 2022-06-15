/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/* 

1 2 3 1

set: 1 2 3 1 2 3

2 3

3 1

*/

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      std::unordered_set<int> theSet;
      int theSize = nums.size();
      for (int i = 0; i < theSize; i++) {
        int theNumber = nums[i];
        if (theSet.count(theNumber))
          return true;
        theSet.emplace(theNumber);
        if (k < theSet.size())
          theSet.erase(nums[i - k]);
      }
      return false;
    }
};

// @lc code=end

