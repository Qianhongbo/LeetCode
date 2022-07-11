/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int theMaxProfit = 0;
    int theLowestPrice = INT_MAX;

    for (const int& price: prices) {
      if (price < theLowestPrice) {
        theLowestPrice = price;
      } else if (price - theLowestPrice > theMaxProfit) {
        theMaxProfit = price - theLowestPrice;
      }
    }
    return theMaxProfit;
  }
};
// @lc code=end
