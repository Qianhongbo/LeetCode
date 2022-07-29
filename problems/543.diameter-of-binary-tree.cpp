/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

#include <algorithm>

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
  int maxDiameter{0};
  int diameterOfBinaryTree(TreeNode *root) {
    getMaxDepth(root);
    return maxDiameter;
  }

  int getMaxDepth(TreeNode *root) {
    // base case
    if (nullptr == root) {
      return 0;
    }

    int leftMax = getMaxDepth(root->left);
    int rightMax = getMaxDepth(root->right);
    maxDiameter = std::max(maxDiameter, leftMax + rightMax);
    return std::max(leftMax, rightMax) + 1;
  }
};
// @lc code=end
