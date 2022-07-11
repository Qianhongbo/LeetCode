/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
  // solution 1: traverse each node of the tree
  // std::vector<int> res;
  // vector<int> postorderTraversal(TreeNode *root) {
  //   traverse(root);
  //   return res;
  // }

  // void traverse(TreeNode *root) {
  //   if (!root) return;
  //   traverse(root->left);
  //   traverse(root->right);
  //   res.push_back(root->val);
  // }

  // solution 2: divide to subtree
  vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> res;
    if (!root) return res;

    std::vector<int> tmp1 = postorderTraversal(root->left);
    res.insert(res.end(), tmp1.begin(), tmp1.end());
    
    std::vector<int> tmp2 = postorderTraversal(root->right);
    res.insert(res.end(), tmp2.begin(), tmp2.end());
    
    res.push_back(root->val);

    return res;
  }
};
// @lc code=end
