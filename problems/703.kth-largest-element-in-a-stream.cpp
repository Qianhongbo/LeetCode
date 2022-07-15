/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class KthLargest {
 public:
  int count;
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

  KthLargest(int k, const vector<int>& nums)
  : count(k) {
    for (const auto& n: nums) {
      pq.push(n);
      if (pq.size() > k) {
        pq.pop();
      }
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > count) {
      pq.pop();
    }
    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
