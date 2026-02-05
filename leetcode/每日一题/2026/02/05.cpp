//https://leetcode.cn/problems/transformed-array/description/?envType=daily-question&envId=2026-02-05

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        for(int i = 0;i < n;i++){

            int x = nums[i];

            if(x > 0){
                res[i] = (nums[(i + nums[i]) % n]);
            }else if(x < 0){
                res[i] = (nums[((i - abs(nums[i])) % n + n )% n]);
            }
        }

        return res;
    }
};