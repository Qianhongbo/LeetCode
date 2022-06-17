/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
 public:
  // vector<string> topKFrequent(vector<string>& words, int k) {
  //   std::unordered_map<std::string, int> count;
  //   int maxFreq{1};
  //   for (const auto& word : words) {
  //     maxFreq = std::max(maxFreq, ++count[word]);
  //   }

  //   std::unordered_map<int, std::vector<string> > bucket;
  //   for (const auto& kv: count) {
  //     bucket[kv.second].push_back(kv.first);
  //   }

  //   std::vector<string> res;
  //   for (int i{maxFreq}; i > 0; i--) {
  //     auto it = bucket.find(i);
  //     if (it == bucket.end()) continue;
  //     std::sort(it->second.begin(),it->second.end());
  //     res.insert(res.end(), it->second.begin(), it->second.end());
  //     if (res.size() >= k) return std::vector<string>(res.begin(), res.begin() + k);
  //   }

  //   return res;
  // }

  vector<string> topKFrequent(vector<string>& words, int k) {
    std::unordered_map<std::string, int> count;
    for (const std::string& word: words) {
      count[word]++;
    }

    typedef std::pair<std::string, int> Node;
    auto comp = [](const Node& a, const Node& b) {
      if (a.second == b.second) {
        return a.first < b.first;
      }
      return a.second > b.second;
    };

    std::priority_queue<Node, std::vector<Node>, decltype(comp)> q(comp);

    for (const auto& kv: count) {
      q.push(kv);
      if (q.size() > k) {
        q.pop();
      }
    }

    std::vector<std::string> ans;

    while(!q.empty()) {
      ans.push_back(q.top().first);
      q.pop();
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
