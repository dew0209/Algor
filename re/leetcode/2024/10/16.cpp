//题目链接：https://leetcode.cn/problems/minimum-average-of-smallest-and-largest-elements/description/?envType=daily-question&envId=2024-10-16



class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int op = n / 2;
        int l = 0,r = n - 1;
        op--;
        double res = double(nums[l] + nums[r]) / 2;
        while(op){
            l++;
            r--;
            res = min(res,double(nums[l] + nums[r]) / 2);
            op--;
        }
        return res;
    }
};