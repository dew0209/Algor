#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7;

int f[N];

void dfs(int r){
    if(r < 0)return;
    int s = sqrt(r * 2);
    s *= s;
    int l = s - r;dfs(l - 1);
    for(;l <= r;l++,r--){
        f[l] = r,f[r] = l;
    }
}

void solve(){
    int n;cin >> n;
    dfs(n - 1);
    for(int i = 0;i < n;i++){
        cout << f[i] << ' ';
    }
    cout << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}