//https://codeforces.com/contest/1406/problem/B
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
LL ans;

void solve(){
    cin >> n;
    vector<LL> a(n);
    LL mv = -1e9;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        mv = max(mv,a[i]);
    }
    sort(a.begin(),a.end());
    LL res = LONG_LONG_MIN;
    res = max(res,a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5]);
    res = max(res,a[0] * a[1] * a[2] * a[3] * a[4]);
    res = max(res,a[n - 1] * a[0] * a[1] * a[2] * a[3]);
    res = max(res,a[0] * a[1] * a[n - 1] * a[n - 2] * a[n - 3]);
    cout << res << endl;
    
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}