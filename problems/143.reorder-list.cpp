/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
class Solution {
public:
    void reorderList(ListNode* head) {
      ListNode* slow = head;
      ListNode* fast = head;
      
      // find a middle node
      // in 1->2->3->4->5->6 find 4 
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      
      // reverse the second part of the list
      // convert 1->2->3->4->5->6 into 1->2->3->4 and 6->5->4
      // reverse the second half in-place
      ListNode* prev = nullptr;
      ListNode* curr = slow;
      ListNode* nextTmp = nullptr;
      
      while (curr) {
        nextTmp = curr->next;
        
        curr->next = prev;
        prev = curr;
        curr = nextTmp;
      }
      
      // merge two lists
      // merge 1->2->3->4 and 6->5->4 into 1->6->2->5->3->4
      ListNode* first = head;
      ListNode* second = prev;
      while (second->next) {
        nextTmp = first->next;
        first->next = second;
        first = nextTmp;
        
        nextTmp = second->next;
        second->next = first;
        second = nextTmp;
      }
    }
};
// @lc code=end

