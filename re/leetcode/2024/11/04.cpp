//题目链接：https://leetcode.cn/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-11-04

class Solution {
public:
    bool judgeSquareSum(int c) {
        int r = sqrt(c);
        int l = 0;

        while(l <= r){
            if(l * l == c - r * r){
                return true;
            }
            if(l * l < c - r * r){
                l++;
            }else {
                r--;
            }
        }
        return false;
    }
};