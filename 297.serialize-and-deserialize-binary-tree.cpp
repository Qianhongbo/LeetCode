/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>
#include <sstream>
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

class Codec {
 public:
  void preorderEncode(TreeNode* root, std::string& s) {
    if (!root) {
      s += "# ";
      return;
    }
    s += std::to_string(root->val) + " ";
    preorderEncode(root->left, s);
    preorderEncode(root->right, s);
  }

  string serialize(TreeNode* root) {
    std::string s;
    preorderEncode(root, s);
    return s;
  }

  // return the root of the deserilized tree
  TreeNode* preorderDecode(std::stringstream& ss) {
    std::string s;
    ss >> s;
    if (s == "#") {
      return nullptr;
    }
    TreeNode* root = new TreeNode(std::stoi(s));
    root->left = preorderDecode(ss);
    root->right = preorderDecode(ss);
    return root;
  }

  TreeNode* deserialize(const string& data) {
    std::stringstream ss{data};
    TreeNode* root = preorderDecode(ss);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
