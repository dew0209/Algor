//https://codeforces.com/problemset/problem/1343/C 双指针

#include <iostream>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 200010;

int n;
int a[N];

int sgn(int u){
    return u > 0 ? 1 : -1;
}

void solve(){
    cin >> n;
    LL sum = 0;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++){
        int cur = a[i];
        int j = i;
        while(j <= n && sgn(a[i]) == sgn(a[j])){
            cur = max(cur,a[j]);
            ++j;
        }
        sum += cur;
        i = j - 1;
    }
    cout << sum << endl;
}

int main(){
    int T;cin >> T;
    while(T--){
        solve();
    }
    return 0;
}