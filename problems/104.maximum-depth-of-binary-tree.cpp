/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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

#include <algorithm>

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
  // solution 1: divide the tree to subtree
  int maxDepth(TreeNode *root) {
    // base case
    if (!root) return 0;

    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);

    return std::max(leftMax, rightMax) + 1;
  }

  // solution 2: traverse the whole tree
  // int depth; // the depth of each node
  // int res;   // final result 
  // int maxDepth(TreeNode *root) {
  //   traverse(root);
  //   return res;
  // }

  // void traverse(TreeNode* root) {
  //   if (!root) return;

  //   depth++;
  //   if (!root->left && !root->right) {
  //     // arrive the leaf of the tree
  //     res = std::max(res, depth);
  //   }
  //   traverse(root->left);
  //   traverse(root->right);
  //   depth--;
  // }
};
// @lc code=end
