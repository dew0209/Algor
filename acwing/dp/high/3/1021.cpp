/*
 * 货币系统：
 *   n种货币系统，组成面值为m的方案数
 *   和买书是一个道理
 *   完全背包求方案数
 *   设f[i][j]：从1~i种选择，面值为j的所有选择方案数
 *   f[i][j] = f[i - 1][j] + f[i][j - a[i]];
 */

#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 100010;

int n,m;
LL f[N];

void solve(){
    cin >> n >> m;
    f[0] = 1;
    for(int i = 1;i <= n;i++){
        int c;cin >> c;
        for(int j = c;j <= m;j++){
            f[j] += f[j - c];
        }
    }
    cout << f[m] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}