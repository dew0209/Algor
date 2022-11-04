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

int n;
int p[N];
int a,b,c,d,e;
LL ans[5];
pair<LL,LL> q[5];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> p[i];
    for(int i = 0;i < 5;i++){
        int c;cin >> c;
        q[i] = {c,i};
    }
    sort(q,q + 5);
    LL res = 0;
    for(int i = 0;i < n;i++){
        res += p[i];
        int j = 4;
        for(int j = 4;j >= 0;j--){
            ans[q[j].se] += res / q[j].fi;
            res %= q[j].fi;
        }
    }
    for(int i = 0;i < 5;i++)cout << ans[i] << ' ';
    cout << endl;
    cout << res << endl;
    return 0;
}