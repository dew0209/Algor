/*
 * 感觉这题稍微有点问题
 *  如果出去和进入需要时间，最少也是2 * N 个单位时间，但是这题只给了2 * N - 1 个单位时间，2 * N - 1 可以转化为只能向右或者向下走的，这两者是等价的。和摘花生是一样的问题
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

const int N = 110;

int n,m;
int a[N][N],f[N][N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            cin >> a[i][j];
    memset(f,0x3f,sizeof f);
    f[0][1] = 0;
    f[1][0] = 1;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            f[i][j] = min(f[i - 1][j],f[i][j - 1]) + a[i][j];

    cout << f[n][n] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();
    return 0;
}