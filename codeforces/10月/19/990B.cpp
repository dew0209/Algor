#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,k;
int q[N];

void solve(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++)cin >> q[i];
    sort(q + 1,q + n + 1);
    q[++n] = 2e9;
    int res = 0;
    int u = 1;
    for(int i = 1;i < n;i++){
        while(u < n && q[i] == q[u])u++;
        if(q[u] - q[i] > k)res++;
    }
    cout << res << endl;
}

int main(){
    solve();
    return 0;
}