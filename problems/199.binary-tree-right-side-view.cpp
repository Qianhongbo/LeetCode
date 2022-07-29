/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

#include <vector>
using namespace std;

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
  int depth{0};
  std::vector<int> res;
  vector<int> rightSideView(TreeNode *root) {
    traverse(root);
    return res;
  }

  void traverse(TreeNode *root) {
    if (nullptr == root) {
      return;
    }

    depth++;
    if (res.size() < depth) {
      res.push_back(root->val);
    }

    traverse(root->right);
    traverse(root->left);

    depth--;
  }
};
// @lc code=end
