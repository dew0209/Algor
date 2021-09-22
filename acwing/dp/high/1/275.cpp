/*
 * 等于传纸条的证明：
 *      两条路径有重合，那么其中一条，在重合的地方可以转化为其他路径，这样答案不会变小，还可能变大
 *      0 0 0
 *      9 0 0
 *      9 0 0
 *      两条都走 0 -> 9 -> 9 -> 0 -> 0
 *      将其中一条转化为0 -> 0 -> 0 -> 0 -> 0
 *      这样答案不会变小，因为点的值是 >= 0的
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <deque>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;

const int N = 55,M = N * 2;

int n,m;
int g[N][N];
int f[M][N][N];

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> g[i][j];
    for(int to = 2;to <= n + m;to++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                int& v = f[to][i][j];
                int y1 = to - i;
                int y2 = to - j;
                if(y1 < 1 || y1 > m || y2 < 1 || y2 > m)continue;
                int t = g[i][y1];
                if(i != j)t += g[j][y2];
                v = max(v,f[to - 1][i - 1][j - 1] + t);
                v = max(v,f[to - 1][i][j - 1] + t);
                v = max(v,f[to - 1][i][j] + t);
                v = max(v,f[to - 1][i - 1][j] + t);

            }
        }
    }
    cout << f[n + m][n][n] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();
    return 0;
}