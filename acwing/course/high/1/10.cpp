//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n,m;
int f[N][N];
int h[N],e[N],w[N],v[N],ne[N];
int idx;


void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u){
    for(int i = v[u];i <= m;i++){
        f[u][i] = w[u];
    }
    for(int i = h[u];~i;i = ne[i]){
        int t = e[i];
        dfs(t);
        for(int j = m;j >= v[u];j--){
            for(int k = 0;k <= j - v[u];k++){
                f[u][j] = max(f[u][j],f[u][j - k] + f[t][k]);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    int root = 1;
    for(int i = 1;i <= n;i++){
        
        int p;
        cin >> v[i] >> w[i] >> p;
        if(p == -1)root = i;
        else add(p,i);
    }
    dfs(root);
    cout << f[root][m] << endl;
    return 0;
}