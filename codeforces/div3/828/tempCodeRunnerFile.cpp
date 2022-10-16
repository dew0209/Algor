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
    //二分
    int a,b,c,d;cin >> a >> b >> c >> d;
    LL l = a * b;
    LL r = c * d;
    LL k = r / l;
    LL rx = -1,ry = -1;
    cout << k << endl;
    for(int i = a + 1;i <= c;i++){
        for(int len = 1;len <= k;len++){
            if((len * l) % i != 0)continue;
            LL searce = len * l / i;
            //if(i == 12 && len == 2)cout << searce << "--" << b << "---" << d << endl;
            if(searce > b && searce <= d){
                //if(i == 12 && len == 2)cout << searce << "--" << b << "---" << d << endl;
                rx = i,ry = searce;
                break;
            }
        }
        if(rx != -1)break;
    }
    cout << rx << " " << ry << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}