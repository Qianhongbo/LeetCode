/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

#include <algorithm>
#include <cstdlib>

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
  bool res{true};
  bool isBalanced(TreeNode* root) {
    maxDepth(root);
    return res;
  }

  int maxDepth(TreeNode* root) {
    // base case 
    if (nullptr == root) {
      return 0;
    }

    if (!res) {
      return -1;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if (std::abs(leftDepth - rightDepth) > 1) {
      res = false;
    }

    return std::max(leftDepth, rightDepth) + 1;
  }
};
// @lc code=end
