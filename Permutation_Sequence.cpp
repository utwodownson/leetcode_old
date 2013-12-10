/* The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
    public:
        string getPermutation(int n, int k) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> nums(n);  
            int permCount =1;  
            for (int i = 0; i < n; ++i) {  
                nums[i] = i + 1;  
                permCount *= (i + 1);        
            }  

            k--;  
            string targetNum;  
            for (int i = 0; i < n; ++i) {    
                permCount = permCount / (n - i);  
                int choosed = k / permCount;  
                targetNum.push_back(nums[choosed] + '0');  

                for (int j = choosed; j < n - i; ++j) nums[j]=nums[j + 1];  
                k = k % permCount;  
            }  
            return targetNum;  
        }
};
