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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int main(){
    LL a,b,c,d;cin >> a >> b >> c;
    LL mv = max(a,max(b,c));
    LL res = 0;
    if(a < mv){
        res += mv - 1 - a;
    }
    if(b < mv){
        res += mv - 1 - b;
    }
    if(c < mv){
        res += mv - 1 - c;
    }
    cout << res << endl;
    return 0;
}