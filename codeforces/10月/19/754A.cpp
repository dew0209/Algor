#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
int q[N];
int s[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    vector<pair<int,int>> res;
    for(int i = 1;i <= n;i++)s[i] = q[i] + s[i - 1];
    if(s[n] != 0){
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << ' ' << n << endl;
        return;
    }
    for(int i = 1;i <= n;i++){
        if(s[i] != 0){
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << 1 << ' ' << i << endl;
            cout << i + 1 << ' ' << n << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int T = 1;
    solve();
    return 0;
}