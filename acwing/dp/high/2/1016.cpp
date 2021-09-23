/*
 * 最大上升子序列的和
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

const int N = 110;

int n,m;
int a[N];
int f[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    int res = 0;
    for(int i = 1;i <= n;i++){
        f[i] = a[i];
        for(int j = 1;j < i;j++){
            if(a[i] > a[j])f[i] = max(f[i],f[j] + a[i]);
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