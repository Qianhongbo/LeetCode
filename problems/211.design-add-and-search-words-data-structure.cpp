/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

#include <memory>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Trie {
 private:
  struct TrieNode {
    TrieNode() : isWord(false), children(26, nullptr) {
      for (int i{0}; i < 26; i++) {
        children[i] = nullptr;
      }
    }

    ~TrieNode() {
      for (TrieNode* child : children) {
        if (child) {
          delete child;
        }
      }
    }

    bool isWord;
    std::vector<TrieNode*> children;
  };

  TrieNode* root;

 public:
  Trie() : root(new TrieNode) {}

  ~Trie() {
    delete root;
  }

  void insert(const std::string& aStr) {
    TrieNode* p = root;
    for (const char c : aStr) {
      int idx = c - 'a';
      if (nullptr == p->children[idx]) {
        p->children[idx] = new TrieNode();
      }
      p = p->children[idx];
    }
    p->isWord = true;
  }

  bool hasKeyWithPattern(const std::string& pattern) {
    return hasKeyWithPattern(root, pattern, 0);
  }

  bool hasKeyWithPattern(TrieNode* node, const std::string& pattern, int i) {
    // base case
    if (!node) {
      return false;
    }

    if (i == pattern.size()) {
      return node->isWord;
    }

    char c = pattern[i];
    if ('.' != c) {
      return hasKeyWithPattern(node->children[c - 'a'], pattern, i + 1);
    }

    for (int j{0}; j < 26; j++) {
      if (hasKeyWithPattern(node->children[j], pattern, i + 1)) {
        return true;
      }
    }

    return false;
  }
};

class WordDictionary {
 public:
  WordDictionary() : trie() {
  }

  void addWord(string word) {
    trie.insert(word);
  }

  bool search(string word) {
    return trie.hasKeyWithPattern(word);
  }

  Trie trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
