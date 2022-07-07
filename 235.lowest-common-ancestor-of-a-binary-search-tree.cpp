/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// ! need to be commented before submitting
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    // make it easier for the following steps
    if (p->val > q->val) return lowestCommonAncestor(root, q, p);

    if (p->val <= root->val && root->val <= q->val) {
      // p <= root <= q
      // both p and q are at the left subtree and the right subtree of root
      // root is LCA
      return root;
    }
    if (root->val > q->val) {
      // both p and q are at the left subtree of root
      return lowestCommonAncestor(root->left, p, q);
    } else {
      // both p and q are at the right subtree of root
      return lowestCommonAncestor(root->right, p, q);
    }
  }
};
// @lc code=end
