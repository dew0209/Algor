//https://leetcode.cn/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-04-18


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++){
            nums[i] = nums[i] - i;
        }
        map<int,int> cnt;
        //找两两不相等的个数
        for(int i = 0;i < n;i++){
            cnt[nums[i]]++;
        }
        long long res = 0;
        for(auto [k,v] : cnt){
            res = res + (long long)(n - v) * v;
            n -= v;
        }
        return res;
    }
};