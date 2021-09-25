#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int f[N][N];

class Solution {
public:
    int minDistance(string word1, string word2) {
        memset(f,0,sizeof f);
        int n = word1.length();
        int m = word2.length();
        //求一个最长公共子序列即可
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                f[i][j] = max(f[i - 1][j],f[i][j - 1]);
                if(word1[i - 1] == word2[j - 1])f[i][j] = max(f[i][j],f[i - 1][j - 1] + 1);
            }
        }
        int res = n + m - 2 * f[n][m];
        return res;
    }
};