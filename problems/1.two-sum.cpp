/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 
Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1] (return vector of index)
*/

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      // one pass hash table!
      // first check whether the complement is in the hash table
      // if find, return the index,
      // if not, put the value into the hash table
      std::vector<int> res;
      std::unordered_map<int, int> theMap; // number to index map
      int theSize = nums.size();
      for (int i = 0; i < theSize; i++) {
        int theNumber = nums[i];
        int complement = target - theNumber;
        if (theMap.count(complement)) {
          res = {theMap[complement], i};
          break;
        }
        theMap[theNumber] = i;
      }
      return res;
    }
};
// @lc code=end

