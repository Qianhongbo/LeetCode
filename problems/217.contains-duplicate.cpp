/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    // solution 1: sort first 
    // O(nlogn) time | O(1) space
    // bool containsDuplicate(vector<int>& nums) {
    //   std::sort(nums.begin(), nums.end());
    //   size_t theSize = nums.size();
    //   for (size_t i = 0; i < theSize - 1; i++) {
    //     if (nums[i] == nums[i + 1]) {
    //       return true;
    //     }
    //   }
    //   return false;
    // }

    // solution 2: use hash map
    // O(n) time | O(n) space
    bool containsDuplicate(vector<int>& nums) {
      // one way which is not the best!
      // I use this way first...
      // unordered_set<int> theSet(nums.begin(), nums.end());
      // return theSet.size() < nums.size();

      // the performance of this way is better
      // the reason is that we can stop earlier than expected!
      // we don't need to really transform all the element to set
      // we can stop whenever we find an element has been existed in the set.
      unordered_set<int> theSet;
      for(auto& num : nums) {
        if(theSet.count(num)) return true;
        theSet.emplace(num);
        }
      return false;
    }
};
// @lc code=end

