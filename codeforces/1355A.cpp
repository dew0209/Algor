//https://codeforces.com/problemset/problem/1355/A
#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

LL m,k;

LL getXI(LL u){
    LL mx = 0;
    LL mi = 10;
    while (u){
        mx = max(mx,u % 10);
        mi = min(mi,u % 10);
        u /= 10;
    }
    return mx * mi;
}

void solve(){
    cin >> m >> k;
    k--;
    while(k--){
        LL y = getXI(m);
        if(y == 0)break;
        m += y;
    }
    cout << m << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}