/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

#include <memory>
#include <string>
#include <vector>
using namespace std;

// @lc code=start

struct TrieNode {
  TrieNode() : word(nullptr), children(26, nullptr) {
  }

  ~TrieNode() {
    for (TrieNode* child : children) {
      delete child;
    }
  }

  const string* word;
  std::vector<TrieNode*>  children;
};

class Trie {
 public:
  Trie() : root(new TrieNode()) {}

  void insert(const std::string& aStr) {
    TrieNode* p = root.get();
    for (const char c : aStr) {
      int n = c - 'a';
      if (nullptr == p->children[n]) {
        p->children[n] = new TrieNode();
      }
      p = p->children[n];
    }
    p->word = &aStr;
  }

  std::unique_ptr<TrieNode> root;
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    rows = board.size();
    cols = board[0].size();

    // memo.resize(rows, std::vector<bool>(cols, false));

    for (const auto& word : words) {
      trie.insert(word);
    }

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        backtrack(board, trie.root.get(), r, c);
      }
    }

    return res;
  }

  void backtrack(vector<vector<char>>& board,
                 TrieNode* node,
                 int r,
                 int c) {
    if (!isInBound(r, c) || board[r][c] == '#') {
      return;
    }

    const char curr = board[r][c];
    TrieNode* theNextNode = node->children[curr - 'a'];

    if (!theNextNode) {
      return;
    }

    if (theNextNode->word) {
      res.push_back(*(theNextNode->word));
      theNextNode->word = nullptr;  // prevent repetition
    }

    // memo[r][c] = true;
    board[r][c] = '#';

    for (const auto& [dr, dc] : directions) {
      backtrack(board, theNextNode, r + dr, c + dc);
    }

    // memo[r][c] = false;
    board[r][c] = curr;
  }

  bool isInBound(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
      return false;
    }
    return true;
  }

 protected:
  int rows;
  int cols;
  Trie trie;
  std::vector<std::string> res;
  std::vector<std::pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  // std::vector<std::vector<bool>> memo;
};
// @lc code=end
