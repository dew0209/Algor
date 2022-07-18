#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

const int N = 200010;

int n;
int q[N];
int last[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    for(int i = 1;i <= n;i++)last[i] = 0;
    int ans = n + 1;
    for(int i = 1;i <= n;i++){
        if(last[q[i]]){
            ans = min(i - last[q[i]] + 1,ans);
        }
        last[q[i]] = i;
    }
    if(ans > n)ans = -1;
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}