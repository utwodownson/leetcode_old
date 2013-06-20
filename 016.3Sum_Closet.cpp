class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int len = num.size();
            int closet = 0, flag = 1;
            sort(num.begin(), num.end());
            for (int i = 0; i < len - 1; ++i) {
                for (int j = i + 1, k = len - 1; j < k; ) {
                    int sum = num[i] + num[j] + num[k];
                    if (flag || abs(closet - target) > abs(sum - target)) {
                        closet = sum;
                        flag = 0;
                    }
                    if (sum > target) --k;
                    else if (sum < target) ++j;
                    else return target;
                }
            }
            return closet;
        }
};

