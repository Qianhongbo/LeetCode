/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Trie {
 public:
  Trie() : root(new TrieNode) {}

  void insert(const std::string& word) {
    TrieNode* p = root.get();
    for (const char c : word) {
      if (p->children[c - 'a'] == nullptr) {
        p->children[c - 'a'] = new TrieNode();
      }
      p = p->children[c - 'a'];
    }
    p->isWord = true;
  }

  std::string getShortestPrefix(const std::string& aStr) {
    TrieNode* p = root.get();
    std::string tmp{""};
    for (const char c : aStr) {
      p = p->children[c - 'a'];
      tmp += c;
      if (!p || p->isWord) {
        break;
      }
    }
    return p ? tmp : "";
  }

 protected:
  struct TrieNode {
    TrieNode() : isWord(false), children(26, nullptr) {}

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

  const TrieNode* find(const std::string& prefix) {
    const TrieNode* p = root.get();
    for (const char c : prefix) {
      p = p->children[c - 'a'];
      if (!p) {
        break;
      }
    }
    return p;
  }

  std::unique_ptr<TrieNode> root;
};

class Solution {
 public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    Trie theTrie;
    for (const auto& str : dictionary) {
      theTrie.insert(str);
    }
    std::stringstream ss(sentence);
    std::string theStr;
    std::string res;
    while (ss >> theStr) {
      std::string prefix = theTrie.getShortestPrefix(theStr);
      if ("" != prefix) {
        res += prefix;
      } else {
        res += theStr;
      }
      res += " ";
    }
    res.pop_back();
    return res;
  }
};
// @lc code=end
