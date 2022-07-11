/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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

// ! need to be commented before submitting
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <deque>
#include <vector>
using namespace std;

class Solution {
 public:
  // solution 1
  // recursion

  //   void helper(TreeNode* node, vector<vector<int>>& aVec, int level) {
  //     if (level == aVec.size()) {
  //       aVec.push_back({});
  //     }

  //     aVec[level].push_back(node->val);

  //     if (node->left) {
  //       helper(node->left, aVec, level + 1);
  //     }

  //     if (node->right) {
  //       helper(node->right, aVec, level + 1);
  //     }

  //   }

  //   vector<vector<int>> levelOrder(TreeNode* root) {
  //     if (!root) return {};

  //     std::vector<std::vector<int>> ans{};
  //     helper(root, ans, 0);

  //     return ans;
  //   }

  // solution 2
  // iterative bfs

  vector<vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    if (!root) return ans;

    std::deque<TreeNode *> dq;

    dq.push_back(root);

    int level{0};

    while (!dq.empty()) {
      ans.push_back({});

      int theSize = dq.size();

      for (int i{0}; i < theSize; i++) {
        TreeNode *theNode = dq.front();
        dq.pop_front();

        ans[level].push_back(theNode->val);

        if (theNode->left) dq.push_back(theNode->left);
        if (theNode->right) dq.push_back(theNode->right);
      }

      level++;
    }

    return ans;
  }
};
// @lc code=end
