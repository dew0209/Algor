/*
 * 导弹防御系统
 *  每一个点，可以放到上升的序列也可以放到下降的序列
 *  贪心+dfs即可
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
int up[N],down[N];
int res;

void dfs(int u,int sd,int su){
    if(sd + su >= res)return;
    if(u >= n){
        res = min(res,sd + su);
        return;
    }
    //先放到下降的序列
    int k = 0;
    while(k < sd && down[k] <= a[u])k++;
    int t = down[k];
    if(k >= sd){
        down[k] = a[u];
        dfs(u + 1,sd + 1,su);
    }else {
        down[k] = a[u];
        dfs(u + 1,sd,su);
        down[k] = t;
    }
    //再尝试放到上升的序列
    k = 0;
    while(k < su && up[k] >= a[u])k++;
    t = up[k];
    if(k >= su){
        up[k] = a[u];
        dfs(u + 1,sd,su + 1);
    }else {
        up[k] = a[u];
        dfs(u + 1,sd,su);
        up[k] = t;
    }
}

void solve(){
    while(cin >> n,n){
        res = n;
        for(int i = 0;i < n;i++)cin >> a[i];
        dfs(0,0,0);
        cout << res << endl;
    }
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}