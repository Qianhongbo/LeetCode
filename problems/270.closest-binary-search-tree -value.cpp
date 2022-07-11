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

#include <limits.h>

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
  int res;
  int current{INT_MAX};
  
  int closestValue(TreeNode* root, double target) {
    traverse(root, target);
    return res;
  }
  
  void traverse(TreeNode* root, double target) {
    if (!root) {
      return;
    }
    
    if (abs(target - root->val) < abs(target - current)) {
      current = root->val;
      res = root->val;
    }
    
    if (root->val > target) {
      traverse(root->left, target);
    } else {
      traverse(root->right, target);
    }
  }
};