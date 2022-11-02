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

LL n,m;
LL q[N];

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> q[i];
    }
    sort(q,q + n);
    LL res = 0;
    if(q[n - 1] != q[0]){
        for(int i = n - 1;i > 0;i--){
            res += q[i] - q[0];
        }
    }
    LL diff = m - res;
    if(diff <= 0){
        cout << q[0] << endl;
    }else {
        LL cnt = diff / n;
        LL ans = q[0] - cnt;
        if(diff % n != 0){
            ans--;
        }
        if(ans < 0){
            ans = -1;
        }
        cout << ans << endl;
    }
    return 0;
}