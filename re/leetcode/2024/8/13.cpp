//题目连接：https://leetcode.cn/problems/special-array-i/description/?envType=daily-question&envId=2024-08-13

//思路：一次遍历

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n - 1;i++){
            int a = nums[i] & 1;
            int b = nums[i + 1] & 1;
            if(!(a ^ b)){
                return false;
            }
        }
        return true;
    }
};