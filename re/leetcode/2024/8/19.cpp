//链接：https://leetcode.cn/problems/student-attendance-record-ii/description/?envType=daily-question&envId=2024-08-19

//思路：dp

class Solution {
public:
    int MOD = 1e9 + 7;
    int f[100010][3][3];
    int checkRecord(int n) {
        //前i位 j 个 a，末尾连续k个L
        f[0][0][0] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= 1;j++){
                for(int k = 0;k <= 2;k++){
                    f[i][j][0] = (f[i][j][0] + f[i - 1][j][k]) % MOD;
                }
            }
            for(int k = 0;k <= 2;k++){
                f[i][1][0] = (f[i][1][0] + f[i - 1][0][k])  % MOD;
            }
            for(int j = 0;j <= 1;j++){
                for(int k = 1;k <= 2;k++){
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1]) % MOD;
                }
            }
        }
        int res = 0;
        for(int j = 0;j <= 1;j++){
            for(int k = 0;k <= 2;k++){
                res = (res + f[n][j][k]) % MOD;
            }
        }
        return res;
    }
};