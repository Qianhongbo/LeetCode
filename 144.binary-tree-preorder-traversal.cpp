/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
  // solution 1: iterate through each node
  // std::vector<int> res;

  // vector<int> preorderTraversal(TreeNode *root) {
  //   traverse(root);
  //   return res;
  // }

  // void traverse(TreeNode *root) {
  //   if (!root) return;

  //   res.push_back(root->val);
  //   traverse(root->left);
  //   traverse(root->right);
  // }


  // solution 2: divide to subtree
  vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> res;
    // base case
    if (!root) return res;

    res.push_back(root->val);

    std::vector<int> tmp1 = preorderTraversal(root->left);
    res.insert(res.end(), tmp1.begin(), tmp1.end());
   
    std::vector<int> tmp2 = preorderTraversal(root->right);
    res.insert(res.end(), tmp2.begin(), tmp2.end());

    return res;
  }
};
// @lc code=end
