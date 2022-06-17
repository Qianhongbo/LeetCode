/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
using namespace std;

// @lc code=start
class Solution {
 public:
  // TODO：Solution 1
  // * Time: O(NK) | Space: O(NK) (used by res)
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if(strs.size() == 1) {
      return {{strs[0]}};
    }

    std::unordered_map<std::string, std::vector<string>> theMap;
    for (auto &str : strs) {
      std::array<int, 26> track{};

      for (auto &c : str) {
        track[c - 'a']++;
      }

      std::string temp;
      for (size_t i = 0; i < 26; i++) {
        temp += "#" + std::to_string(track[i]);
      }
      theMap[temp].push_back(str);
    }
    vector<vector<string>> res;
    res.reserve(theMap.size());
    for (auto &pair : theMap) {
      res.push_back(std::move(pair.second));
    }
    return res;
  }

  // // TODO: Solution 2
  // // * Time: O(NKlogK) | Space: O(NK) (used by ans)
  // // sort characters in string
  // vector<vector<string>> groupAnagrams(vector<string>& strs) {
  //   if (strs.size() == 1)
  //     return {{strs[0]}};

  //   vector<vector<string>> ans;
  //   unordered_map<string, vector<string>> M;
  //   for (int i = 0; i < strs.size(); i++) {
  //     string str = strs[i];
  //     sort(strs[i].begin(), strs[i].end());  // Sorting the string
  //     M[strs[i]].push_back(str);             // Sorted string is the key and the value is the initial string
  //   }
  //   for (auto i = M.begin(); i != M.end(); i++)
  //     ans.push_back(i->second);  // Traversing the map and adding the vectors of string to ans
  //   return ans;
  // }
};
// @lc code=end
