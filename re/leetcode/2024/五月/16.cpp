// 题目链接：https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/description/?envType=daily-question&envId=2024-05-16


// 思路：贪心


class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long maxV = 0;
        long long rest = 0;
        int n = milestones.size();
        for(int i = 0;i < n;i++){
            if(maxV < milestones[i]){
                rest = rest + maxV;
                maxV = milestones[i];
            }else {
                rest = rest + milestones[i];
            }
        }
        if(maxV <= rest + 1){
            return maxV + rest;
        }else {
            return 2 * rest + 1;
        }
    }
};