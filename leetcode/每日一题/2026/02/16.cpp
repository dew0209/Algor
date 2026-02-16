//https://leetcode.cn/problems/reverse-bits/description/?envType=daily-question&envId=2026-02-16


class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for(int i = 0;i < 32;i++){
            if((n >> i) & 1){
                res += (1 << (31 - i));
            }
        }
        return res;
    }
};