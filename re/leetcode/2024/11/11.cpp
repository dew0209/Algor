//题目链接：https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/description/?envType=daily-question&envId=2024-11-11


class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        sort(cuts.begin(),cuts.end());

        vector<vector<int>> f(m + 10,vector<int>(m + 10,0));
        for(int i = m - 2;i >= 0;i--){
            for(int j = i + 2;j < m;j++){
                int res = 1e9;
                for(int k = i + 1;k < j;k++){
                    res = min(res,f[i][k] + f[k][j]);
                }
                res += cuts[j] - cuts[i];
                f[i][j] = res;
            }
        }
        return f[0][m - 1];
    }
};