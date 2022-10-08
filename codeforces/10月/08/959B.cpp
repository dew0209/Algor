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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m,k;
map<string,int> d;
int arr[N],cost[N],group[N];

int main(){
    cin >> n >> k >> m;
    for(int i = 1;i <= n;i++){
        string s;cin >> s;
        d[s] = i;
    }
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        cost[i] = INF;
    }
    for(int i = 1;i <= k;i++){
        int x;cin >> x;
        while(x--){
            int a;cin >> a;
            group[a] = i;
            cost[i] = min(cost[i],arr[a]);
        }
    }
    LL ans = 0;
    while(m--){
        string s;cin >> s;
        ans += cost[group[d[s]]];
    }
    cout << ans << endl;
}