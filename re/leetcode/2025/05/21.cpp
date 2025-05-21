//https://leetcode.cn/problems/zero-array-transformation-ii/?envType=daily-question&envId=2025-05-21

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int l = 0,r = queries.size();

        if(!check(nums,queries,r)){
            return -1;
        }

        while(l < r){
            int k = l + r >> 1;
            if(check(nums,queries,k)){
                r = k;
            }else {
                l = k + 1;
            }
        }
        return l;
    }
    
    bool check(vector<int>& nums, vector<vector<int>>& queries,int k){
        int n = nums.size();
        int m = queries.size();

        vector<int> cnt(n + 1,0);

        

        for(int i = 0;i < k;i++){
            cnt[queries[i][0]] += queries[i][2];
            cnt[queries[i][1] + 1] -= queries[i][2];
        }

        for(int i = 1;i < n;i++){
            cnt[i] += cnt[i - 1];
        }

        for(int i = 0;i < n;i++){
            if(nums[i] > cnt[i]){
                return false;
            }
        }


        return true;
    }

};