/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

#include <queue>
using namespace std;

// @lc code=start
class MyStack {
 public:
  MyStack() {
  }

  void push(int x) {
    q.push(x);
    top_ = x;
  }

  int pop() {
    int sz = q.size();
    while (sz > 1) {
      int tmp = q.front();
      q.pop();
      q.push(tmp);
      top_ = tmp;
      sz--;
    }
    int res = q.front();
    q.pop();
    return res;
  }

  int top() {
    return top_;
  }

  bool empty() {
    return q.empty();
  }

 private:
  std::queue<int> q;
  int top_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
