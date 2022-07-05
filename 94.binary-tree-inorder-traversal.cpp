/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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

#include <vector>
using namespace std;

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
  // solution 1: traverse the whole tree
  // std::vector<int> res;
  // vector<int> inorderTraversal(TreeNode *root) {
  //   traverse(root);
  //   return res;
  // }

  // void traverse(TreeNode* root) {
  //   if (!root) return;

  //   traverse(root->left);
  //   res.push_back(root->val);
  //   traverse(root->right);
  // }

  // solution 2: divide the tree to subtree
  vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> res;
    if (!root) return res;

    std::vector<int> temp1 = inorderTraversal(root->left);
    res.insert(res.end(), temp1.begin(), temp1.end());
    res.push_back(root->val);
    std::vector<int> temp2 = inorderTraversal(root->right);
    res.insert(res.end(), temp2.begin(), temp2.end());

    // res.reserve(1 + temp1.size() + temp2.size());
    
    
    return res;
  }
};
// @lc code=end
