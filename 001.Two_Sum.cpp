typedef struct node{
    int idx;
    int val;
    node(){};
    node(int i, int v) : idx(i), val(v){}
}Node;

bool compare(const Node& a, const Node& b){
    return a.val < b.val;
}

class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            int len = numbers.size();
            assert(len >= 2);           

            vector<int> ret(2, 0);
            vector<Node> nums(len);

            for (int i = 0; i < len; i++)
                nums[i] = Node(i+1, numbers[i]);

            sort(nums.begin(), nums.end(), compare);    // O(n*log(n))

            int l = 0;
            int r = len - 1;
            while (l < r) {
                int sum = nums[l].val + nums[r].val;
                if (sum == target){
                    ret[0] = min(nums[l].idx, nums[r].idx);     // val is compare, but idx not
                    ret[1] = max(nums[l].idx, nums[r].idx);
                    break;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }

            return ret;
        }
};

/* class Solution {
     public:
         vector<int> twoSum(vector<int> &numbers, int target) {
                     // Start typing your C/C++ solution below
                     // DO NOT write int main() function

                     int len = numbers.size();
                     assert(len >= 2);           

                     vector<int> ret(2, 0);

                     map<int, int> mapping;              // default all are 0
                     vector<long long> mul(len, 0);

                     for(int i = 0; i < len; i++){
                        mul[i] = (target - numbers[i]) * numbers[i];
                     }

                     if(mapping[mul[i]] > 0) {        // not default 0
                        if(numbers[i] + numbers[mapping[mul[i]] - 1] == target){
                            ret[0] = mapping[mul[i]];
                            ret[1] = i + 1;
                            break;
                        }

                     } else {
                            mapping[mul[i]] = i + 1;    // larger than 0
                     }
                }

                return ret;
         }
}; */
