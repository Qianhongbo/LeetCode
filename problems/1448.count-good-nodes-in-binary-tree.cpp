/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */

#include <limits.h>

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

// ! need to be commented before submitting
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int count{0};

  int goodNodes(TreeNode *root) {
    traverse(root, INT_MIN);
    return count;
  }

  void traverse(TreeNode *root, int maximum) {
    if (nullptr == root) {
      return;
    }

    if (root->val >= maximum) {
      count++;
      maximum = root->val;
    }

    traverse(root->left, maximum);
    traverse(root->right, maximum);
  }
};
// @lc code=end
