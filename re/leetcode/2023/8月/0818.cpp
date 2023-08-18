题目链接：https://leetcode.cn/problems/pizza-with-3n-slices/description/

方法一：动态规划

3n     n

i - 1   i  i + 1


遍历到某个节点的时候，i

可选可不选

0~i中选j个不相邻的数
选了i  i - 1不可能选的  i - 2
没选i  i - 1可选可不选

f[i][j] 表示从i个数中选j个不相邻的数的最大值

f[i][j] = max(f[i - 2][j - 1] + v[i],f[i - 1][j]);

f[n - 1][j];


是一个环：环变成非环，最后一个点和第一个点不能同时选

搞两边动态规划：1 ~ n - 1   0 ~ n - 2


class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        vector<int> a(slices.begin(),slices.end() - 1);
        vector<int> b(slices.begin() + 1,slices.end());
        return max(calc(a),calc(b));
    }
    int calc(vector<int>& v){
        int n = v.size();
        int m = (v.size() + 1) / 3;
        vector<vector<int>> f(n,vector<int>(m + 1,0));
        f[0][0] = 0;
        f[0][1] = v[0];
        f[1][0] = 0;
        f[1][1] = max(v[0],v[1]);
        for(int i = 2;i < n;i++){
            for(int j = 1;j <= m;j++){
                f[i][j] = max(f[i - 2][j - 1] + v[i],f[i - 1][j]);
            }
        }
        return f[n - 1][m];
    }
};