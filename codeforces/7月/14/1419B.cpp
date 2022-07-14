#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 100010;

LL n;

void solve(){
    cin >> n;
    int ans = 0;
    for(LL i = 1;i * (i + 1) / 2 <= n;i = i * 2 + 1){
        //cout << i * 2 + 1 << endl;
        ans++;
        n = n - 1LL * i * (i + 1) / 2;
    }
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}