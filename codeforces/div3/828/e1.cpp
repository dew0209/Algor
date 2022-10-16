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
    int a,b,c,d;cin >> a >> b >> c >> d;
    LL l = a * b;
    LL r = c * d;
    LL k = r / l;
    LL rx = -1,ry = -1;
    for(int i = a + 1;i <= c;i++){
        for(int len = 1;len <= k;len++){
            if((len * 1LL * l) % i != 0)continue;
            LL searce = (len * 1LL * l) / i;
            if(searce > b && searce <= d){
                rx = i,ry = searce;
                break;
            }
        }
        // for(int j = b + 1;j <= d;j++){
        //     if((i * j) % (a * b) == 0){
        //         rx = i,ry = j;
        //         break;
        //     }
        // }
        if(rx != -1)break;
    }
    cout << rx << " " << ry << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}