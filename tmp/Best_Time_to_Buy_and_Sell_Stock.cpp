/* Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction 
 * (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int max = 0, min = INT_MAX, diff = 0;
            for (int i = 0; i < prices.size(); ++i) {
                if (prices[i] < min) min = prices[i];
                diff = prices[i] - min;
                if (max < diff) max = diff;
            }
            return max;
        }
};
