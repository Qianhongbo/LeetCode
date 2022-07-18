/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

#include <stack>
using namespace std;

// @lc code=start
class MyQueue {
 public:
  MyQueue() {
  }

  void push(int x) {
    stk1.push(x);
  }

  int pop() {
    int res = peek();
    stk2.pop();
    return res;
  }

  int peek() {
    if (stk2.empty()) {
      while (!stk1.empty()) {
        int tmp = stk1.top();
        stk1.pop();
        stk2.push(tmp);
      }
    }
    return stk2.top();
  }

  bool empty() {
    return stk1.empty() && stk2.empty();
  }

 private:
  std::stack<int> stk1;
  std::stack<int> stk2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
