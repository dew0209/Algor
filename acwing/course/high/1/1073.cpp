//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010,M = N * 2;

const int INF = 0x3f3f3f3f;

int n;
int h[N],e[M],ne[M],w[M],idx;

int down1[N],down2[N];
int node1[N],node2[N];
int up[N];


void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs_d(int u,int fa){
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(j != fa){
            int d = dfs_d(j,u) + w[i];
            if(d > down1[u]){
                down2[u] = down1[u];
                node2[u] = node1[u];
                down1[u] = d;
                node1[u] = j;
            }else if(d > down2[u]){
                down2[u] = d;
                node2[u] = j;
            }
        }
    }
    return down1[u];
}


void dfs_u(int u,int fa){
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(j != fa){
            if(node1[u] == j){
                up[j] = max(down2[u],up[u]) + w[i];
            }else {
                up[j] = max(down1[u],up[u]) + w[i];
            }
            dfs_u(j,u);
        }
    }
}


int main(){
    
    cin >> n;
    
    memset(h,-1,sizeof h);
    
    for(int i = 0;i < n - 1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    
    dfs_d(1,-1);
    dfs_u(1,-1);
    
    int ans = INF;
    
    for(int i = 1;i <= n;i++){
        ans = min(ans,max(up[i],down1[i]));
    }
    cout << ans << endl;
    
    return 0;
}