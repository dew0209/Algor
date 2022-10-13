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

const int N = 1000010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;

void solve(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    bool ok = false;
    for(int i = 0;i < n - 1;i++){
        if(a[i] >= a[i + 1]){
            ok = true;
            break;
        }
    }
    if(ok)cout << "NO";
    else cout << "YES";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}