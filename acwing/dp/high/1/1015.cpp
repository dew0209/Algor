/*
 *
 * person:往右走或者往下走
 * 2 3 4
 * 1 6 5
 *
 * 2 3
 *   6 5 --> 16
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

const int N = 110;

int n,m,q;
int f[N][N];
int a[N][N];

void solve(){
    cin >> n >> m;
    memset(f,0,sizeof f);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> a[i][j];
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            f[i][j] = max(f[i - 1][j],f[i][j - 1]) + a[i][j];
    cout << f[n][m] << endl;
}


int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}