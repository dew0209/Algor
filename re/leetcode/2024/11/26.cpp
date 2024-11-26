//题目链接：https://leetcode.cn/problems/alternating-groups-i/description/?envType=daily-question&envId=2024-11-26


class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        vector<int> nums(2 * n,0);

        for(int i = 0;i < n;i++){
            nums[i] = nums[i + n] = colors[i];
        }
        int res = 0;

        for(int i = 1;i <= n;i++){
            
            if(nums[i] ^ nums[i - 1] && nums[i] ^ nums[i + 1]){
                res++;
            }
        }
        return res;
    }
};