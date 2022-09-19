#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,s;

int main(){
    cin >> n >> s;
    int res = -1;
    s *= 100;
    bool ok = 0;
    for(int i = 0;i < n;i++){
        int a,b;cin >> a >> b;
        int tmp = a * 100 + b;
        int cnt = 100 - b;
        if(tmp > s)continue;
        ok = 1;
        if(cnt == 100)continue;
        res = max(res,cnt);
    }
    if(ok && res == -1)res = 0;
    cout << res << endl;
}