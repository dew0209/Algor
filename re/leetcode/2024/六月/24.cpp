//题目连接：https://leetcode.cn/problems/next-greater-element-ii/?envType=daily-question&envId=2024-06-24

//思路：单调栈

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int top = -1;
        int st[2 * n];
        vector<int> res(n,-1);
        for(int i = 0;i < 2 * n - 1;i++){
            while(top >= 0 && nums[i % n] > nums[st[top]]){
                res[st[top]] = nums[i % n];
                top--;
            }
            st[++top] = i % n;
        }
        return res;
    }
};