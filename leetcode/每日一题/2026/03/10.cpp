//https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-ii/?envType=daily-question&envId=2026-03-10

const long long MOD = 1e9 + 7;
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        //
        vector<vector<long long>> f0(zero + 1,vector<long long>(one + 1,0));
        vector<vector<long long>> f1(zero + 1,vector<long long>(one + 1,0));
        for(int i = 0;i <= min(limit,zero);i++){
            f0[i][0] = 1;
        }
        for(int i = 0;i <= min(limit,one);i++){
            f1[0][i] = 1;
        }
        for(int i = 1;i <= zero;i++){
            for(int j = 1;j <= one;j++){
                
                if(i > limit){
                    f0[i][j] = f0[i - 1][j] + f1[i - 1][j] - f1[i - limit - 1][j];
                }else {
                    f0[i][j] = f0[i - 1][j] + f1[i - 1][j];
                }
                f0[i][j] = (f0[i][j] % MOD + MOD ) % MOD;
                if(j > limit){
                    f1[i][j] = f1[i][j - 1] + f0[i][j - 1] - f0[i][j - limit - 1];
                }else {
                    f1[i][j] = f1[i][j - 1] + f0[i][j - 1];
                }
                f1[i][j] = (f1[i][j] % MOD + MOD ) % MOD;
            }
        }
        return (f0[zero][one] + f1[zero][one]) % MOD;
    }
};