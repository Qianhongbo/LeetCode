/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // base case
    if (nullptr == list1 && nullptr == list2) return nullptr;
    if (nullptr == list1) return list2;
    if (nullptr == list2) return list1;

    // define a head to return the result
    ListNode* prehead = new ListNode;  // do I need to delete this ptr?
    // use prev to link all the elements
    ListNode* prev = prehead;

    while (list1 && list2) {
      if (list1->val <= list2->val) {
        prev->next = list1;
        list1 = list1->next;
      } else {
        prev->next = list2;
        list2 = list2->next;
      }
      prev = prev->next;
    }

    // if one list has come to the end
    // the while loop will end
    // but there may still some elements on another list
    // link them to the prev end
    prev->next = list1 == nullptr ? list2 : list1;

    // return the next of the prehead
    return prehead->next;
  }
};
// @lc code=end
