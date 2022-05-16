#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 200010;

int n,m;
int q[N];

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
    }
    sort(q + 1,q + 1 + n);
    LL sum = 0;
    LL ans = 0;
    for(int i = 1;i <= n;i++){
        sum += q[i];
        if(sum > m)break;
        ans += (m - sum) / i + 1;
    }
    cout << ans << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}