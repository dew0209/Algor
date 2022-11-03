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

void solve(){
    int n;cin >> n;
    int res = 1;
    while(n){
        if(n & 1)res *= 2;
        n >>= 1;
    }
    cout << res;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}