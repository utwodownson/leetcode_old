/* There N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
class Solution {
    public:
        int candy(vector<int> &ratings) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int n = ratings.size(), sum = 0;
            vector<int> num(n, 1);
            for (int i = 1, k = 2; i < n; ++i) 
                (ratings[i - 1] < ratings[i]) ? num[i] = max(k++, num[i]) : k = 2;
            for (int i = n - 2, k = 2; i >= 0; --i) 
                (ratings[i + 1] < ratings[i]) ? num[i] = max(k++, num[i]) : k = 2;
            for (int i = 0; i < n; ++i) 
                sum += num[i];
            return sum;
        }
};
