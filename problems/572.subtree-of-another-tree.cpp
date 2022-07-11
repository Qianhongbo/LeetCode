/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
  bool isSameTree(TreeNode* p, TreeNode* q) {
      // base case
      
      // first check nullptr
      if (!p && !q) return true;
      if (!p || !q) return false;
      
      // next check value
      // the val of nullptr can not be accessed
      if (p->val != q->val) return false;
      
      return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
  
  
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      // base case
      
      if (!root) return false;
      
      if (isSameTree(root, subRoot)) return true;
      
      return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
// @lc code=end

