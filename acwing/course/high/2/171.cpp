//dfs

#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

const int N = 50;

LL n,m;
LL weights[1 << 25];
int w[N];
int k;
int cnt = 1;
LL ans;

void dfs1(int u,LL s){
    
    if(u == k){
        weights[cnt++] = s;
        return;
    }
    
    dfs1(u + 1,s);
    if(s + w[u] <= m)dfs1(u + 1,s + w[u]);
}

void dfs2(int u,LL s){
    
    if(u == n){
        
        int l = 0,r = cnt - 1;
        
        while(l < r){
            int mid = l + r + 1 >> 1;
            
            if((LL)s + weights[mid] <= m)l = mid;
            else r = mid - 1;
        }
        ans = max(ans,s + weights[l]);
        return;
    }
    
    dfs2(u + 1,s);
    if((LL)s + w[u] <= m)dfs2(u + 1,s + w[u]);
}

int main(){
    
    cin >> m >> n;
    for(int i = 0;i < n;i++)cin >> w[i];
    
    sort(w,w + n);
    reverse(w,w + n);
    k = n / 2;
    dfs1(0,0);
    
    sort(weights,weights + cnt);
    cnt = unique(weights,weights + cnt) - weights;
    
    dfs2(k,0);
    
    cout << ans << endl;
    return 0;
}