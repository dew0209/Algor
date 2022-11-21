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

const int N = 110;

void solve(){
    int l,r,x;cin >> l >> r >> x;
    int a,b;cin >> a >> b;
    int la = a - l >= x;
    int ra = r - a >= x;
    int lb = b - l >= x;
    int rb = r - b >= x;
    if(a == b){
        cout << 0;
    }else if(abs(a - b) >= x) {
        cout << 1;
    }else if((la && lb) || (ra && rb)){
        cout << 2;
    }else if((la && rb) || (ra && lb)){
        cout << 3;
    }else {
        cout << -1;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}