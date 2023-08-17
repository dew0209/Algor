题目链接：https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza/

方法一：动态规划 + 二维前缀和


1：不是每一个位置都有苹果
2：f[i][j] = f[i+1.....k][j] + f[i][j + 1....q] (k < n q < m)
3：次数 f[k][i][j]：从(i,j)到(n - 1,m - 1)切成k块的方案数

f[k][i][j] = f[k - 1][i1~n-1][j] + f[k-1][i][j1~m-1]

sum[i][j] = pizza[i][j]是否是苹果 + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];

const int MOD = 1e9 + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();
        vector<vector<int>> sum(n + 2,vector<int>(m + 2,0));
        for(int i = n;i >= 1;i--){
            for(int j = m;j >= 1;j--){
                sum[i][j] = (pizza[i - 1][j - 1] == 'A') + sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
            }
        }
        vector<vector<vector<int>>> f(k + 1,vector<vector<int>>(n + 1,vector<int>(m + 1,0)));
        for(int k1 = 1;k1 <= k;k1++){
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= m;j++){
                    if(k1 == 1){
                        f[k1][i][j] = (sum[i][j] > 0);
                        continue;
                    }
                    for(int i1 = i + 1;i1 <= n;i1++){
                        if(sum[i][j] > sum[i1][j]){
                            f[k1][i][j] = (f[k1][i][j] + f[k1 - 1][i1][j]) % MOD;
                        }
                    }
                    for(int j1 = j + 1;j1 <= m;j1++){
                        if(sum[i][j] > sum[i][j1]){
                            f[k1][i][j] = (f[k1][i][j] + f[k1 - 1][i][j1]) % MOD;
                        }
                    }
                }
            }
        }
        return f[k][1][1];
    }
};


方法二：针对方法一的优化

f[k1][i][j]：

f[k1][i][j]：
sum[i][j] = sum[i + 1][j]  f[k1][i][j] = f[k1][i + 1][j];
sum[i][j] = sum[i][j + 1]  f[k1][i][j] = f[k1][i][j + 1];

const int MOD = 1e9 + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();
        vector<vector<int>> sum(n + 2,vector<int>(m + 2,0));
        for(int i = n;i >= 1;i--){
            for(int j = m;j >= 1;j--){
                sum[i][j] = (pizza[i - 1][j - 1] == 'A') + sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
            }
        }
        vector<vector<int>> f(n + 2,vector<int>(m + 2,0));
        for(int k1 = 1;k1 <= k;k1++){
            vector<int> a(m + 1);
            for(int i = n;i >= 1;i--){
                int b = 0;
                for(int j = m;j >= 1;j--){
                    int tmp = f[i][j];
                    if(k1 == 1){
                        f[i][j] = (sum[i][j] > 0);
                        continue;
                    }
                    if(sum[i][j] == sum[i + 1][j]){
                        f[i][j] = f[i + 1][j];
                    }else if(sum[i][j] == sum[i][j + 1]){
                        f[i][j] = f[i][j + 1];
                    }else {
                        f[i][j] = (a[j] + b) % MOD;
                    }
                    a[j] = (a[j] + tmp) % MOD;
                    b = (b + tmp) % MOD;
                }
            }
        }
        return f[1][1];
    }
};