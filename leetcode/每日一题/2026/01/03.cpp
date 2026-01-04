//https://leetcode.cn/problems/number-of-ways-to-paint-n-3-grid/?envType=daily-question&envId=2026-01-03


class Solution {
public:
    int MOD = 1e9 + 7;
    int canUse[12][3] = {
        {0,1,2},{0,2,1},{0,1,0},{0,2,0},
        {1,0,1},{1,0,2},{1,2,0},{1,2,1},
        {2,0,1},{2,0,2},{2,1,0},{2,1,2}
    };
    int numOfWays(int n) {
        vector<vector<int>> cnt(12);
        for(int i = 0;i < 12;i++){
            for(int j = 0;j < 12;j++){
                if(i != j && check(i,j)){
                    cnt[i].push_back(j);
                }
            }
        }
        vector<vector<int>> f(n + 1,vector<int>(12,0));
        for(int i = 0;i < 12;i++){
            f[1][i] = 1;
        }

        for(int i = 2;i <= n;i++){
            //上一行的状态
            for(int j = 0;j < 12;j++){
                for(auto x : cnt[j]){
                    f[i][x] = (f[i][x] + f[i - 1][j]) % MOD;
                }
            }
        }

        int res = 0;
        for(int i = 0;i < 12;i++){
            res = (res + f[n][i]) % MOD;
        }
        return res;
    }

    bool check(int i,int j){
        for(int t = 0;t < 3;t++){
            int a = canUse[i][t];
            int b = canUse[j][t];
            if(a == b){
                return false;
            }
        }
        return true;
    }

};