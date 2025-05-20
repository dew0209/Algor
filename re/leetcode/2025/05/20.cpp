//https://leetcode.cn/problems/zero-array-transformation-i/description/?envType=daily-question&envId=2025-05-20

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> cnt(n + 1,0);

        

        for(int i = 0;i < m;i++){
            cnt[queries[i][0]]++;
            cnt[queries[i][1] + 1]--;
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