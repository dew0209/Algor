#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int main(){
    int l,r,x,y,k;
    cin >> l >> r >> x >> y >> k;
    bool ok = false;
    for(int i = x;i <= y;i++){
        LL otherVal = i * 1LL * k;
        if(otherVal <= r && otherVal >= l){
            ok = true;
            break;
        }
    }
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}