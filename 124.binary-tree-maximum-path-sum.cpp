/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
using namespace std;

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
  int maxPathSum(TreeNode* root) {
    // the path sum will have four circumstances
    // 1 : only root
    // 2 : root and one side
    // 3 : root and both sides
    int res = INT_MIN;
    oneSideMaxSum(root, res);
    return res;
  }

  // compute one side sum including the root value
  int oneSideMaxSum(TreeNode* root, int& res) {
    // base case
    if (!root) {
      return 0;
    }

    int theLeftSideMaxSum = std::max(0, oneSideMaxSum(root->left, res));
    int theRightSideMaxSum = std::max(0, oneSideMaxSum(root->right, res));

    int thePathSum = theLeftSideMaxSum + theRightSideMaxSum + root->val;
    res = std::max(res, thePathSum);

    return std::max(theLeftSideMaxSum, theRightSideMaxSum) + root->val;
  }
};
// @lc code=end
