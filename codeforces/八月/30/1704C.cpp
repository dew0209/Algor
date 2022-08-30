#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m;
LL q[N];
LL cnt[N];

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> q[i];
    }
    sort(q + 1,q + 1 + m);
    q[m + 1] = q[1] + n;
    int idx = 0;
    for(int i = 1;i <= m;i++){
        cnt[idx++] = q[i + 1] - q[i] - 1;
    }
    sort(cnt,cnt + idx);
    LL sum = 0,tmp = 0;
    for(int i = idx - 1;i >= 0;i--){
        if(cnt[i] - tmp * 2 > 0){
            LL addVal = max(1LL,cnt[i] - tmp * 2 - 1);
            sum += addVal;
        }
        tmp += 2;   
    }
    cout << n - sum;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}