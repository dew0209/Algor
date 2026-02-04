//https://leetcode.cn/problems/trionic-array-ii/?envType=daily-question&envId=2026-02-04

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int p,q;

        long long ans = LLONG_MIN;
        long long res = LLONG_MIN;
        long long max_v = 0;

        for(int i = 0;i < n;i++){
            int j = i + 1;
            long long res = 0;
            max_v = 0;
            //第一段
            for(;j < n && nums[j - 1] < nums[j];j++){

            }
           
            p = j - 1;
            if(p == i){
                continue;
            }
            res += nums[p] + nums[p - 1];
            //第二段
            for(;j < n && nums[j - 1] > nums[j];j++){
                res += nums[j];
            }
            q = j - 1;

            if(q == p || q == n - 1 || (nums[j] == nums[q])){
                continue;
            }
            //第三段
            res += nums[q + 1];

            
            //处理第一段最大值
            long long sum = 0;
            for(int t = p - 2;t >= i;t--){
                sum += nums[t];
                max_v = max(max_v,sum);
            }
            res += max_v;

            max_v = 0;
            sum = 0;
            //处理第三段最大值
            for(int t = q + 2;t < n && nums[t] > nums[t - 1];t++){
                sum += nums[t];
                max_v = max(max_v,sum);
            }
            res += max_v;

            ans = max(ans,res);
            i = q - 1;
        }
        return ans;
    }
};