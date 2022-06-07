#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 0x3f3f3f3f;

int a[110];

void solve(){
    int n,u,v;cin >> n >> u >> v;
    for(int i = 1;i <= n;i++)cin >> a[i];
    int ans = N;
    for(int i = 2;i <= n;i++){
        int diff = abs(a[i] - a[i - 1]);
        if(diff >= 2)ans = 0;
        if(diff == 1)ans = min(ans,min(u,v));
        if(diff == 0)ans = min(ans,v + min(u,v));
    }
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}