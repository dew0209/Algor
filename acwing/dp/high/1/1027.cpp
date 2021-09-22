/*
 * 走两次，两次总和应该最大
 * 设在某一时刻，第一条路行走的位置在点(x1,y1),第二条路行走的位置在点(x2,y2).
 * 我们可以得到：
 *      最终状态 x1 = x2 y1 = y2, x1 + y1 = x2 + y2
 * 将两次行走归为一次行走：那么每个时刻x1 + y1 = x2 + y2 （因为时间花费是一样的）
 * 不妨设f[n][x1][x2]：n = x1 + y1 = x2 + y2
 *     那么可以有四种状态更新过来：0 1 代表向右走或者向下走
 *                           1.01
 *                           2.00
 *                           3.11
 *                           4.10
 * f[n][x1][y1] = max(01,11,10,00) + w
 *    w 为该次能获得到的分数
 *      if x1 != x2 ---> t = g[x1][n - x1] + g[x2][n - x2]
 *      else ---> t = g[x1][n - x1] (或者 g[x2][n - x2]，此刻，所处的位置在同一个点);
 *
 * 跑两次dp可以吗?
 *   见1027_1
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

const int N = 15,M = N * 2;

int n,m;
int g[N][N];
int f[M][N][N];

void solve(){
    cin >> n;
    int a,b,c;
    while (cin >> a >> b >> c,a || b || c)g[a][b] = c;
    for(int to = 2;to <= n * 2;to++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                int& v = f[to][i][j];
                int y1 = to - i;
                int y2 = to - j;
                if(y1 < 1 || y1 > n || y2 < 1 || y2 > n)continue;
                int t = g[i][y1];
                if(i != j)t += g[j][y2];
                v = max(v,f[to - 1][i - 1][j - 1] + t);
                v = max(v,f[to - 1][i][j - 1] + t);
                v = max(v,f[to - 1][i][j] + t);
                v = max(v,f[to - 1][i - 1][j] + t);
            }
        }
    }
    cout << f[n * 2][n][n] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();
    return 0;
}