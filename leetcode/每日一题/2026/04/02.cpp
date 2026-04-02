//https://leetcode.cn/problems/maximum-amount-of-money-robot-can-earn/description/?envType=daily-question&envId=2026-04-02


class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> f(n + 1,vector<vector<int>>(m + 1,vector<int>(3,0)));

        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= m;j++){
                f[i][j][0] = f[i][j][1] = f[i][j][2] = -2e9;
            }
        }
        f[0][0][0] = 0;
        f[0][1][0] = 0;
        f[1][0][0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
            
                int t = coins[i - 1][j - 1];
                f[i][j][0] = max(f[i - 1][j][0],f[i][j - 1][0]) + t;
                
                int& v1 = f[i][j][1];
                v1 = max(f[i - 1][j][1] + t,f[i][j - 1][1] + t);

                if(t < 0){
                    v1 = max(v1,f[i - 1][j][0]);
                    v1 = max(v1,f[i][j - 1][0]);
                }

                int& v2 = f[i][j][2];
                v2 =max(f[i - 1][j][2],f[i][j - 1][2]) + t;
                if(t < 0){
                    v2 = max(v2,max(f[i - 1][j][1],f[i][j - 1][1]));
                }
            }
        }
        
        return max(f[n][m][0],max(f[n][m][1],f[n][m][2]));
    }
};