//k <= n - m
//k >= m + 1
//n - m + 1 >= m + 1
//n >= 2m
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int q[N];
int p[N];

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
        p[i] = q[i];
    }
    bool ok = 1;
    sort(q + 1,q + 1 + n);
    for(int i = max(0,n - m + 1);i <= min(n,m);i++){
        if(q[i] != p[i]){
            ok = 0;
        }
    }
    
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}