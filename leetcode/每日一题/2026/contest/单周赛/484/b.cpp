//https://leetcode.cn/problems/number-of-centered-subarrays/description/


class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> f(n + 1,0);
        vector<int> sum(n + 1,0);

        f[0] = 1;

        for(int i = 1;i <= n;i++){
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int res = 0;

        for(int i = 1;i <= n;i++){

            for(int j = i;j <= n;j++){
                int ans = sum[j] - sum[i - 1];

                for(int k = i;k <= j;k++){
                    if(nums[k - 1] == ans){
                        res++;
                        break;
                    }   
                }
                
            }
            
        }
        
        return res;
    }
};