题目链接：https://leetcode.cn/problems/find-the-k-or-of-an-array/description/?envType=daily-question&envId=2024-03-06

思路：二进制枚举

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        vector<int> cnt(32,0);
        for(int i = 0;i < 32;i++){
            for(int j = 0;j < n;j++){
                if((nums[j] >> i) & 1){
                    cnt[i]++;
                }
            }
            if(cnt[i] >= k){
                res = res + (1 << i);
            }
        }
        return res;
    }
};