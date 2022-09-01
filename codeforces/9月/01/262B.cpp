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

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m,res,minv;
int main(){
    minv = INF;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        minv = min(abs(x),minv);
        res += x;
        if(x < 0 && m){
            res -= x * 2;
            m--;
        }
    }
    cout << res - (m % 2 ? minv * 2 : 0) << endl;

    return 0;
}