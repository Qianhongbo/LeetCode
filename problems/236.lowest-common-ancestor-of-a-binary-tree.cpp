/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    return find(root, p->val, q->val);
  }

  // find the root which the val1 and val2 is on the left subtree 
  // or on the right subtree or on the root
  TreeNode* find(TreeNode* root, int val1, int val2) {
    // base case
    if (!root) {
      return nullptr;
    }

    // preorder
    // if we find the root is equal to val1 or val2
    // which means that we find it we can just return 
    if (root->val == val1 || root->val == val2) {
      return root;
    }

    TreeNode* left = find(root->left, val1, val2);
    TreeNode* right = find(root->right, val1, val2);

    // postorder
    // if we find both left and right
    // which means that we find the target root
    if (left != nullptr && right != nullptr) {
      return root;
    }

    // return left or right depends on which side we find
    return left == nullptr ? right : left;
  }
};
// @lc code=end
