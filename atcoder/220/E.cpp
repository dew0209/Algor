#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fi first
#define se second

using namespace std;

const int N = 1000010,M = N * 2,MOD = 998244353;

typedef long long LL;

int n,m;
LL f[N];

void solve(){
    cin >> n >> m;
    f[0] = 1;
    LL ans = 0;
    for(int i = 1;i <= n;i++)f[i] = f[i - 1] * 2LL % MOD;
    for(int l = 0;l <= m;l++){
        int r = m - l;
        if(l >= n || r >= n)continue;
        int k = max(l,r);
        LL cnt = f[n - k] - 1;
        ans += (cnt * f[max(0,l - 1)] % MOD * f[max(r - 1,0)] % MOD);
        ans %= MOD;
    }
    cout << ans * 2 % MOD << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}