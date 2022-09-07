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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
int q[N];
int st[N];
int cnt[N];

int res[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        st[i] = cnt[i] = res[i] = 0;
    }
    for(int i = 0;i < n;i++){
        cin >> q[i];
        st[q[i]] = 1;
        //cnt[q[i]] = 1;
    }
    int fi = 1;
    while(st[fi])fi++;
    bool ok = true;
    for(int i = 0;i < n;i++){
        if(!cnt[q[i]]){
            res[i] = q[i];
            cnt[q[i]] = 1;
        }else {
            res[i] = fi;
            if(fi > q[i]){
                ok = false;
                break;
            }
            cnt[fi] = 1;
            while(cnt[fi])fi++;
        }
    }
    if(!ok)cout << -1;
    else {
        for(int i = 0;i < n;i++){
            cout << res[i] << ' ';
        }
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}