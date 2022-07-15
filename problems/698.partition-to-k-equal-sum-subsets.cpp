/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

#include <numeric>  // ! for std::accumulate
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
 public:
  // solution 1: from number point of view
  // bool canPartitionKSubsets(vector<int>& nums, int k) {
  //   if (k > nums.size()) {
  //     return false;
  //   }
  //   std::sort(nums.begin(), nums.end(), std::greater<int>());
  //   int sum = std::accumulate(nums.begin(), nums.end(), 0);

  //   if (0 != sum % k) {
  //     return false;
  //   }

  //   int target = sum / k;  // this is the sum of each bucket
  //   std::vector<int> bucket(k, 0);
  //   return backtrack(nums, target, bucket, 0);
  // }

  // bool backtrack(vector<int>& nums, int target, std::vector<int>& bucket, int index) {
  //   // we have put all the nums to buckets
  //   if (index == nums.size()) {
  //     for (int i{0}; i < bucket.size(); i++) {
  //       if (bucket[i] != target) {
  //         return false;
  //       }
  //     }
  //     return true;
  //   }

  //   for (int i{0}; i < bucket.size(); i++) {
  //     if (bucket[i] + nums[index] > target) {
  //       continue;
  //     }
  //     bucket[i] += nums[index];
  //     if (backtrack(nums, target, bucket, index + 1)) {
  //       return true;
  //     }
  //     bucket[i] -= nums[index];
  //   }

  //   return false;
  // }

  // solution 2: from bucket point of view

  // bool canPartitionKSubsets(vector<int>& nums, int k) {
  //   if (k > nums.size()) {
  //     return false;
  //   }

  //   int sum = std::accumulate(nums.begin(), nums.end(), 0);
  //   if (0 != sum % k) {
  //     return false;
  //   }

  //   int target = sum / k;  // this is the sum of each bucket
  //   std::vector<bool> used(nums.size(), false);
  //   return backtrack(nums, k, target, 0, used, 0);
  // }

  // bool backtrack(vector<int>& nums, int k,
  //                int target, int bucket,
  //                std::vector<bool>& used, int start) {
  //   if (0 == k) {
  //     // we have used all of the number in nums
  //     // which means that all the buckets are full
  //     return true;
  //   }

  //   if (bucket > target) {
  //     return false;
  //   }

  //   if (bucket == target) {
  //     // this bucket has been full
  //     // move to next bucket
  //     bool res = backtrack(nums, k - 1, target, 0, used, 0);
  //     return res;
  //   }

  //   // iterate through all the numbers
  //   for (int i{start}; i < nums.size(); i++) {
  //     if (used[i]) {
  //       continue;
  //     }

  //     if (nums[i] + bucket > target) {
  //       continue;
  //     }
      
  //     bucket += nums[i];
  //     used[i] = true;
  //     if (backtrack(nums, k, target, bucket, used, i + 1)) {
  //       return true;
  //     }
  //     bucket -= nums[i];
  //     used[i] = false;
  //   }
  //   return false;
  // }

  // solution 3: improve from bucket point of view

  std::unordered_map<int, bool> memo;

  bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (k > nums.size()) {
      return false;
    }

    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (0 != sum % k) {
      return false;
    }

    int target = sum / k;  // this is the sum of each bucket
    int used{0};
    return backtrack(nums, k, target, 0, used, 0);
  }

  bool backtrack(vector<int>& nums, int k,
                 int target, int bucket,
                 int& used, int start) {
    if (0 == k) {
      // we have used all of the number in nums
      // which means that all the buckets are full
      return true;
    }

    if (bucket > target) {
      return false;
    }

    if (bucket == target) {
      // this bucket has been full
      // move to next bucket
      bool res = backtrack(nums, k - 1, target, 0, used, 0);
      memo[used] = res;
      return res;
    }

    if (memo.count(used)) {
      return memo.at(used);
    }

    // iterate through all the numbers
    for (int i{start}; i < nums.size(); i++) {
      if ((used >> i) & 1) {
        continue;
      }

      if (nums[i] + bucket > target) {
        continue;
      }
      
      bucket += nums[i];
      used |= 1 << i;
      if (backtrack(nums, k, target, bucket, used, i + 1)) {
        return true;
      }
      bucket -= nums[i];
      used ^= 1 << i;
    }
    return false;
  }
};
// @lc code=end
