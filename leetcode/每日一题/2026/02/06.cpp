//https://leetcode.cn/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-06

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        //两个方向
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int res = n - 1;
        for(int i = 0;i < n;i++){
            long long x = 1LL * nums[i] * k;

            int l = i + 1;int r = n - 1;

            while(l < r){
                int mid = l + r + 1 >> 1;
                if(nums[mid] <= x)l = mid;
                else {
                    r = mid - 1;
                }
            }
            if(l < n && nums[l] <= x){
                res = min(res,i + n - 1 - l);
            }

        }
        return res;
    }
};