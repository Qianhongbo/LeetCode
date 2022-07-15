/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

#include <queue>
using namespace std;

// @lc code=start
class MedianFinder {
 public:
  std::priority_queue<int> large;
  std::priority_queue<int, std::vector<int>, std::greater<int>> small;

  MedianFinder() {
  }

  void addNum(int num) {
    if (large.size() >= small.size()) {
      large.push(num);
      small.push(large.top());
      large.pop();
    } else {
      small.push(num);
      large.push(small.top());
      small.pop();
    }
  }

  double findMedian() {
    if (large.size() < small.size()) {
      return small.top();
    } else if (large.size() > small.size()) {
      return large.top();
    }
    return (large.top() + small.top()) / 2.0;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
