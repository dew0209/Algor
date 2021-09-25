/*
 * 多重背包单调队列优化版本[很难，直接原地暴毙]
 *
 * dp[i][j] = max(dp[i-1][j], dp[i-1][j-v] + w, dp[i-1][j-2*v] + 2*w,..., dp[i-1][j-k*v] + k*w)
 *
 * dp[j]    =     dp[j]
 * dp[j+v]  = max(dp[j], dp[j+v] - w) + w
 * dp[j+2v] = max(dp[j], dp[j+v] - w, dp[j+2v] - 2w) + 2w
 * dp[j+3v] = max(dp[j], dp[j+v] - w, dp[j+2v] - 2w, dp[j+3v] - 3w) + 3w
 * ...
 * 这样，每次入队的值是 dp[j+k*v] - k*w
 *
 * j j+v j+2v j+3v j+4v j+5v j+6v...
 *    |...................|
 *        |...................|
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int f[N];
int q[N],g[N];

void solve(){
    cin >> n >> m;
    int v,w,s;
    for(int i = 0;i < n;i++){
        cin >> v >> w >> s;
        memcpy(g,f,sizeof g);
        for(int j = 0;j < v;j++){
            int hh = 0,tt = -1;
            for(int k = j;k <= m;k += v){
                if(hh <= tt && q[hh] < k - s * v)hh++;
                while(hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w)tt--;
                q[++tt] = k;
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }
    cout << f[m] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}