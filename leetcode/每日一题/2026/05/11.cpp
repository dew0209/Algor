//https://leetcode.cn/problems/separate-the-digits-in-an-array/description/?envType=daily-question&envId=2026-05-11

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> cnt;
        for(int i = 0;i < n;i++){
            int x = nums[i];
            while(x){
                cnt.push_back(x % 10);
                x /= 10;
            }
            for(int j = cnt.size() - 1;j >= 0;j--){
                res.push_back(cnt[j]);
            }
            cnt.clear();
        }
        return res;
    }
};