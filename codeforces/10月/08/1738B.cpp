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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,k;
LL res[N];
LL ans[N];

void solve(){
    cin >> n >> k;
    for(int i = n - k + 1;i <= n;i++)cin >> ans[i];
    for(int i = n - k + 2;i <= n;i++)res[i] = ans[i] - ans[i - 1];
    bool ok = true;
    if(ans[n - k + 1] > res[n - k + 2] * (n - k + 1))ok = false;
    for(int i = n - k + 2;i < n;i++)
        if(res[i] > res[i + 1])ok = false;
    if(k == 1)ok = true;
    if(ok)cout << "YES";
    else cout << "NO";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    
    return 0;
}