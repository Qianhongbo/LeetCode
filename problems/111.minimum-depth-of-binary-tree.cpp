/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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

#include <queue>

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
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }

    std::queue<TreeNode *> q;
    q.push(root);
    int depth{1};

    while (!q.empty()) {
      int sz = q.size();
      for (int i{0}; i < sz; i++) {
        TreeNode *curr = q.front();
        q.pop();
        if (!curr->left && !curr->right) {
          return depth;
        }
        if (curr->left) {
          q.push(curr->left);
        }
        if (curr->right) {
          q.push(curr->right);
        }
      }
      depth++;
    }
    return depth;
  }
};
// @lc code=end
