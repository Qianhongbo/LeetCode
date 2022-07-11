/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;


    // ! i <= n 
    // ! because we want to find the previous node of the node we want to delete
    for (int i{0}; i <= n; i++) {
      first = first->next;
    }

    while (first) {
      first = first->next;
      second = second->next;
    }

    second->next = second->next->next;

    return dummy->next;
  }
};
// @lc code=end
