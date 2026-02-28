//https://leetcode.cn/problems/concatenation-of-consecutive-binary-numbers/description/?envType=daily-question&envId=2026-02-28

const int MOD = 1e9 + 7;
class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        int t = 0;
        for(int i = 1;i <= n;i++){
            int x = i;
            if((x & (x - 1)) == 0){
                t++;
            }
            res = ((res << t) | x) % MOD;
        }
        return res;
    }
};