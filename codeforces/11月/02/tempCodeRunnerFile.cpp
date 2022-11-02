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

int q[N];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
        q[i] += q[i - 1];
    }
    LL res = 0;
    while(m--){
        int l,r;cin >> l >> r;
        if(q[r] - q[l - 1] > 0){
            res += q[r] - q[l - 1];
        }
    }
    cout << res << endl;

    return 0;
}