//https://codeforces.com/problemset/problem/1385/C
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n;
int q[N];

int sign(int u){
    return u >= 0 ? 1 : -1;
}

//上升下降可以 单调也可以

void solve(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> q[i];
    int ans = 2;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    int c = q[n - 2] - q[n - 1];
    bool ok = 1;
    for(int i = n - 3;i >= 0;i--){
        if(sign(c) == sign(q[i] - q[i + 1])){
            ans++;
        }else if(sign(c) > 0 && sign(q[i] - q[i + 1]) < 0 && ok){
            ok = 0;
            c = q[i] - q[i + 1];
            ans++;
        }else if(q[i] == q[i + 1]){
            ans++;
        }else break;
    }
    cout << n - ans << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}