/*
 * There N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
class Solution {
  public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = ratings.size();
        vector<int> buff(len, 1);
        for (int i = 1, k = 2; i < len; ++i) {
            if (ratings[i - 1] < ratings[i])
                buff[i] = max(k++, buff[i]);
            else
                k = 2;
        }

        for (int i = len - 2, k = 2; i >= 0; --i) {
            if (ratings[i + 1] < ratings[i])
                buff[i] = max(k++, buff[i]);
            else
                k = 2;
        }
        int sum = 0;
        for (int i = 0; i < len; ++i)
            sum += buff[i];
        return sum;
    }
};
