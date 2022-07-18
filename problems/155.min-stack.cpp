/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <stack>
using namespace std;

// @lc code=start
class MinStack {
 public:
  MinStack() {
  }

  void push(int val) {
    stk.push(val);
    if (minStk.empty() || val <= minStk.top()) {
      minStk.push(val);
    }
  }

  void pop() {
    if (minStk.top() == stk.top()) {
      minStk.pop();
    }

    stk.pop();
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return minStk.top();
  }

 private:
  std::stack<int> stk;
  std::stack<int> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
