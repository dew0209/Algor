//https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> f(n + 1,vector<int>(m + 1,0x3f3f3f3f));
        f[0][0] = 0;
        for(int i = 1;i <= n;i++){
            f[i][0] = f[i - 1][0] + s1[i - 1];
        }
        for(int i = 1;i <= m;i++){
            f[0][i] = f[0][i - 1] + s2[i - 1];
        }

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                f[i][j] = f[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 0 + s1[i - 1] + s2[j - 1]);
                f[i][j] = min(f[i][j],f[i - 1][j] + s1[i - 1]);
                f[i][j] = min(f[i][j],f[i][j - 1] + s2[j - 1]);
            }
        }
        return f[n][m];
    }
};