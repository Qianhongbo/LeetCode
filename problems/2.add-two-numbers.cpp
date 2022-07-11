/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// ! need to be commented before submitting
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode tmp = ListNode();
    ListNode* dummy = &tmp;
    ListNode* curr = dummy;

    int carry{0};
    while (l1 || l2 || carry > 0) {
      int theVal1{0}, theVal2{0};

      if (l1) {
        theVal1 = l1->val;
        l1 = l1->next;
      }

      if (l2) {
        theVal2 = l2->val;
        l2 = l2->next;
      }

      int theSum = theVal1 + theVal2 + carry;

      carry = theSum / 10;
      int real = theSum % 10;

      curr->next = new ListNode(real);
      curr = curr->next;
    }

    return dummy->next;
  }
};
// @lc code=end
