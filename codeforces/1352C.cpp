#include <iostream>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 100010;

int n,k;

void solve(){
    cin >> n >> k;
    LL res = 0;
    while(k >= n){
        int cnt = k / n;
        res += n * cnt;
        k -= (n - 1) * cnt;
    }
    cout << res + k << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}