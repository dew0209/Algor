//https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/?envType=daily-question&envId=2026-01-02


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        map<int,int> cnt;
        for(int num : nums){
            cnt[num]++;
        }
        for(auto [x,y] : cnt){
            if(y == n / 2){
                return x;
            }
        }
        return -1;
    }
};