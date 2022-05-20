#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

void solve(){
    long long n,m,ans = 1;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        ans = (ans * n) % MOD;
    }
    cout << ans ;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}