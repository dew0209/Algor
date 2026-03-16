class Solution {
public:
    
    vector<int> get(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n,0);
        res[0] = 1;
        res[1] = 2;
        for(int i = 2;i < n;i++){
            if(nums[i - 2] + nums[i] == nums[i - 1] * 2){
                res[i] = res[i - 1] + 1;
            }else {
                res[i] = 2;
            }
        }
        return res;
    }
    
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = get(nums);
        reverse(nums.begin(),nums.end());
        vector<int> suf = get(nums);
        reverse(nums.begin(),nums.end());
        reverse(suf.begin(),suf.end());
        int ans = 0;
        //替换端点或者整个数组是等差的，pre[i] + 1必须放在这，不能放ans + 1 >= n里面，比如例子：[1,2,6,7]
        for(int i = 0;i < n;i++){
            ans = max(ans,pre[i] + 1);
        }
        if(ans >= n){
            return n;
        }

        for(int i = 1;i < n - 1;i++){
            int d2 = nums[i + 1] - nums[i - 1];
            if(d2 % 2){
                continue;
            }
            bool l = i > 1 && nums[i - 1] - nums[i - 2] == d2 / 2;
            bool r = i + 2 < n && nums[i + 2] - nums[i + 1] == d2 / 2;

            if(l && r){
                ans = max(ans,pre[i - 1] + suf[i + 1] + 1);
            }else if(l){
                ans = max(ans,pre[i - 1] + 1 + 1);
            }else if(r){
                ans = max(ans,suf[i + 1] + 1 + 1);
            }
        }
        return ans;
    }
};