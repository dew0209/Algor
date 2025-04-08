//https://leetcode.cn/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/?envType=daily-question&envId=2025-04-08

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            map<int,int> cnt;
            int k = n - 1;
            while(k >= 0){
                if(cnt[nums[k]])break;
                cnt[nums[k]]++;
                k--;
            }
            return (k + 1 + 2 ) /3;
        }
    };