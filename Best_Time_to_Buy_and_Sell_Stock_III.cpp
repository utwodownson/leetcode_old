/* Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int n = prices.size();
            if (n <= 1) return 0;

            vector<int> left(n, 0), right(n, 0);

            int mx = prices[n - 1], mn = prices[0], ans = 0;

            for(int i = 1; i < n; ++i) {
                left[i] = max(left[i - 1], prices[i] - mn);
                if (prices[i] < mn) mn = prices[i];
            }
            for (int i = n - 2; i >= 0; --i) {
                right[i] = max(right[i + 1], mx - prices[i]);
                if (mx < prices[i]) mx = prices[i];
            }
            for (int i = 0; i < n; ++i) 
                ans = max(ans, left[i] + right[i]);
            return ans;
        }
};
