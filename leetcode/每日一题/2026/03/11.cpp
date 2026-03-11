//https://leetcode.cn/problems/complement-of-base-10-integer/?envType=daily-question&envId=2026-03-11

class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n)return 1;
        int res = 0;
        int t = 0;
        while(n){
            if(!(n & 1)){
                res += (1 << t);
            }
            n >>= 1;
            t++;
        }
        return res;
    }
};