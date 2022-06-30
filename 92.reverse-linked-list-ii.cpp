/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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

// struct ListNode {
//   int val;
//   ListNode* next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head == nullptr) return nullptr;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (left > 1) {
      prev = curr;
      curr = prev->next;
      left--;
      right--;
    }
    
    ListNode* con = prev;
    ListNode* tail = curr;
    while (right > 0) {
      ListNode* nextTmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTmp;
      right--;
    }
    
    if (con != nullptr) {
      con->next = prev;
    } else {
      head = prev;
    }
    
    tail->next = curr;
    return head;
  }
};
// @lc code=end
