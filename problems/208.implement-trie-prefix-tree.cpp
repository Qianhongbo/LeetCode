/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

#include <memory>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Trie {
 public:
  Trie() : root{new TrieNode()} {
  }

  void insert(string word) {
    TrieNode* p = root.get();
    for (const char c: word) {
      if (!p->children[c - 'a']) {
        p->children[c - 'a'] = new TrieNode();
      }
      p = p->children[c - 'a'];
    }
    p->isWord = true;
  }

  bool search(string word) {
    const TrieNode* p = find(word);
    return p && p->isWord;
  }

  bool startsWith(string prefix) {
    return nullptr != find(prefix);
  }

 private:
  struct TrieNode {
    TrieNode() : isWord(false), children(26, nullptr) {}

    ~TrieNode() {
      for (TrieNode* child: children) {
        if (child) {
          delete child;
        }
      }
    }
    bool isWord;
    std::vector<TrieNode*> children;
  };

  const TrieNode* find(const std::string& prefix) const {
    const TrieNode* p = root.get();
    for (const char c: prefix) {
      p = p->children[c - 'a'];
      if (nullptr == p) {
        break;
      }
    }
    return p;
  }

  std::unique_ptr<TrieNode> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
