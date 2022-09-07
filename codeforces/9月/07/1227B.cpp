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
int res[N];

void solve(){
    cin >> n;
    bool ok = true;
    for(int i = 1;i <= n;i++){
        res[i] = i;
    }
    for(int i = 1;i <= n;i++){
        int a;cin >> a;
        if(a < i){
            ok = false;
        }
        if(a > i){
            swap(res[a],res[i]);
        }
    }
    if(!ok)cout << -1;
    else {
        for(int i = 1;i <= n;i++){
            cout << res[i] << ' ';
        }
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}