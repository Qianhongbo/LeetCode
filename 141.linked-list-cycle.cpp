/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  // Time: O(n) | Space: O(n)
    // bool hasCycle(ListNode *head) {
    //   std::set<ListNode*> theSet;
    //   while (head) {
    //     if (theSet.count(head)) {
    //       return true;
    //     }
    //     theSet.insert(head);
    //     head = head->next;
    //   }
    //   return false;
    // }
  // Time: O(n) | Space: O(1)
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (slow != fast) {
      if (fast == nullptr || fast->next == nullptr) {
        return false;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return true;
  }
};
// @lc code=end

