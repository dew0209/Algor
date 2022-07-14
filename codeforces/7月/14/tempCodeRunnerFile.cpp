#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;

void solve(){
    cin >> n;
    int ans = 0;
    for(int i = 1;i * (i + 1) / 2 <= n;i++){
        ans++;
        n -= i * (i + 1);
    }
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}