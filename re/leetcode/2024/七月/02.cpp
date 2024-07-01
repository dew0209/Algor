//题目连接：https://leetcode.cn/problems/maximum-prime-difference/description/?envType=daily-question&envId=2024-07-02

//思路：遍历

class Solution {
public:
    bool check(int u){
        if(u < 2)return false;
        for(int i = 2;i <= u / i;i++){
            if(u % i == 0){
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        int b = -1;
        for(int i = 0;i < n;i++){
            if(check(nums[i])){
                a = i;
                break;
            }
        }
        for(int i = n - 1;i >= 0;i--){
            if(check(nums[i])){
                b = i;
                break;
            }
        }
        return b - a;
    }
};