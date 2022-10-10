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

void solve(){
    int n,x,y,d;cin >> n >> x >> y >> d;
    //能直接到达
    int diff = abs(x - y);
    int res = INF;
    if(diff % d == 0){
        res = diff / d;
    }
    //到达左端点再到y
    int lf = (x - 1 + d - 1) / d;
    if((y - 1) % d == 0){
        res = min(res,lf + (y - 1) / d);
    }
    //到达右端点再到y
    int rf = (n - x + d - 1) / d;
    if((n - y) % d == 0){
        res = min(res,rf + (n - y) / d);
    }
    if(res == INF)res = -1;
    cout << res;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}