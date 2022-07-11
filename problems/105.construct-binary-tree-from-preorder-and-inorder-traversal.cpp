/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

#include <unordered_map>
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
  std::unordered_map<int, int> valToIndex;

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int theSize = inorder.size();
    for (int i{0}; i < theSize; i++) {
      valToIndex[inorder[i]] = i;
    }

    return build(preorder, 0, preorder.size() - 1,
                 inorder, 0, inorder.size() - 1);
  }

  // helper function
  TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                  vector<int> &inorder, int inStart, int inEnd) {
    // base case
    if (preStart > preEnd) return nullptr;

    // the root value is the start number of preorder traversal
    int theRootVal = preorder[preStart];
    int theIndex = valToIndex.at(theRootVal);

    int theLeftSize = theIndex - inStart;
    TreeNode *root = new TreeNode(theRootVal);
    root->left = build(preorder, preStart + 1, preStart + theLeftSize,
                       inorder, inStart, theIndex - 1);
    root->right = build(preorder, preStart + theLeftSize + 1, preEnd,
                       inorder, theIndex + 1, inEnd);

    return root;
  }
};
// @lc code=end
