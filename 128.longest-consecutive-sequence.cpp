/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  // Time: O(n) | Space: O(n)
  int longestConsecutive(vector<int>& nums) {
    if (!nums.size()) return 0;
    // remove duplicate numbers using hashset
    std::set<int> theSet;
    for (const int& theNum : nums) {
      theSet.insert(theNum);
    }

    int ans{1};
    for (const int& theNum : theSet) {
      if (!theSet.count(theNum - 1)) {
        int theCopy{theNum};  // need to copy the number
        int temp{1};
        while (theSet.count(++theCopy)) {
          temp++;
        }
        ans = std::max(ans, temp);
      }
    }

    return ans;
  }
};
// @lc code=end
