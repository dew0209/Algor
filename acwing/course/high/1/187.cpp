//dp


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int ans;
int up[N],down[N];
int g[N];


void dfs(int u,int su,int sd){
    
    if(su + sd >= ans){
        return;
    }
    if(u == n){
        ans = min(ans,su + sd);
        return;
    }
    
    int k = 0;
    int x = g[u];
    //上升
    while(k < su && x <= up[k])k++;
    
    if(k < su){
        int t = up[k];
        up[k] = x;
        dfs(u + 1,su,sd);
        up[k] = t;
    }else {
        up[k] = x;
        dfs(u + 1,su + 1,sd);
    }
    
    k = 0;
    //下降
    while(k < sd && x >= down[k])k++;
    if(k < sd){
        int t = down[k];
        down[k] = x;
        dfs(u + 1,su,sd);
        down[k] = t;
    }else {
        down[k] = x;
        dfs(u + 1,su,sd + 1);
    }
}

void solve(){
    for(int i = 0;i < n;i++){
        cin >> g[i];
    }
    dfs(0,0,0);
    cout << ans << endl;
}

int main(){
    while(scanf("%d",&n),n){
        ans = n;
        solve();
    }
    return 0;
}