/*
 * 友好城市
 * 7
 * 22 4
 * 2 6
 * 10 3
 * 15 12
 * 9 8
 * 17 17
 * 4 2
 * 选择 4 - 2
 *     10 - 3
 *     15 - 12
 *     17 - 17
 * 解决：先排序->在依靠另一个端点进行最长上升子序列->得出结果
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <deque>
#include <queue>
#include <set>

using namespace std;

#define fi first
#define se second

typedef long long LL;
typedef pair<int,int> PII;

const int N = 1010;

int n,m;
PII a[N];
int f[N];

void solve(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> a[i].fi >> a[i].se;
    sort(a,a + n);
    int res = 0;
    for(int i = 0;i < n;i++){
        f[i] = 1;
        for(int j = 0;j < i;j++){
            if(a[i].se > a[j].se)f[i] = max(f[i],f[j] + 1);
        }
        res = max(res,f[i]);
    }
    cout << res << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}