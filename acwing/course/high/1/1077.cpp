//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1510,M = N * 2;

int n;
int h[N],e[M],ne[M],idx;
int f[N][3];
int w[N];
int st[N];

void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u){
    f[u][2] = w[u];
    
    int sum = 0;
    
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        dfs(j);
        f[u][0] += min(f[j][1],f[j][2]);
        f[u][2] += min(min(f[j][0],f[j][1]),f[j][2]);
        sum += min(f[j][1],f[j][2]);
    }
    
    f[u][1] = 1e9;
    
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        f[u][1] = min(sum - min(f[j][1],f[j][2]) + f[j][2],f[u][1]);
    }
}

int main(){
    
    cin >> n;
    
    memset(h,-1,sizeof h);
    
    int a,k,cnt,b;
    for(int i = 1;i <= n;i++){
        cin >> a >> k >> cnt;
        w[a] = k;
        while(cnt--){
            cin >> b;
            add(a,b);
            st[b] = 1;
        }
    }
    
    int root = 1;
    while(st[root])root++;
    
    dfs(root);
    
    cout << min(f[root][1],f[root][2]) << endl;
    
    return 0;
}