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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

LL n,m;

int main(){
    cin >> n >> m;
    while(m--){
        LL x,y;cin >> x >> y;
        LL cnt = (x - 1) * n + y;
        cnt = (cnt + 1) >> 1;
        if((x + y) % 2 == 1){
            cnt += (n * n + 1) >> 1;
        }
        cout << cnt << endl;
    }
    return 0;
}