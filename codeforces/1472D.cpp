#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N  = 200010;

int n;
int a[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    long long ans = 0;
    int ok = 1;
    sort(a + 1,a + n + 1);
    for(int i = n;i >= 1;i--){
        if(ok){
            if(a[i] % 2 == 0)ans += a[i];
        }else if(a[i] % 2)ans -= a[i];
        ok ^= 1;
        //cout << ans << "debug" << endl;
    }
    if(ans > 0)cout << "Alice";
    else if(ans < 0)cout << "Bob";
    else cout << "Tie";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}