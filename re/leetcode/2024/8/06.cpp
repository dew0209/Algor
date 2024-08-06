//题目连接：https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-i/description/?envType=daily-question&envId=2024-08-06



typedef long long LL;
const int mod = 1e9 + 7;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<LL>> dp1(zero + 1,vector<LL>(one + 1,0));
        vector<vector<LL>> dp0(zero + 1,vector<LL>(one + 1,0));

        for(int i = 0;i <= min(zero,limit);i++){
            dp0[i][0] = 1;
        }
        for(int j = 0;j <= min(one,limit);j++){
            dp1[0][j] = 1;
        }
        for(int i = 1;i <= zero;i++){
            for(int j = 1;j <= one;j++){
                if(i > limit){
                    dp0[i][j] = ((dp0[i - 1][j] + dp1[i - 1][j]) % mod - dp1[i - limit - 1][j]) % mod;
                }else {
                    dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j]) % mod;
                }
                dp0[i][j] = (dp0[i][j] + mod) % mod;
                if(j > limit){
                    dp1[i][j] = ((dp1[i][j - 1] + dp0[i][j - 1]) % mod - dp0[i][j - limit - 1]) % mod;
                }else {
                    dp1[i][j] = (dp1[i][j - 1] + dp0[i][j - 1]) % mod;
                }
                dp1[i][j] = (dp1[i][j] + mod) % mod;
            }
        }
        return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};