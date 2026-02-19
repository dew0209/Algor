//https://leetcode.cn/problems/binary-number-with-alternating-bits/description/?envType=daily-question&envId=2026-02-18

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = - 1;

        while(n){
            int t = n & 1;
            if(last == -1){
                last = t;
            }else if(last == t) {
                return false;
            }
            last = t;
            n = n / 2;
        }
        return true;
    }
};