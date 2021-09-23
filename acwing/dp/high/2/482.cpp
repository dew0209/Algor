/*
 * 合唱队形
 *  满足登山的情况下，求最少需要几位同学出列-->求一个最大的登山-->用总人数减去即可
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
int a[N];
int f[N],d[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++){
        f[i] = 1;
        for(int j = 1;j < i;j++){
            if(a[i] > a[j])f[i] = max(f[i],f[j] + 1);
        }
    }
    for(int i = n;i >= 1;i--){
        d[i] = 1;
        for(int j = n;j > i;j--){
            if(a[i] > a[j])d[i] = max(d[i],d[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i++)
        res = max(res,f[i] + d[i] - 1);
    cout << n - res << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}