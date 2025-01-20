//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 40010,M = N * 2;

int n,m;
int h[N],e[M],ne[M],idx;
int q[N];
int f[N][16];
int deepth[N];

void add(int a,int b){
    
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
    
}

void bfs(int root){
    
    memset(deepth,0x3f,sizeof deepth);
    
    int hh = 0,tt = 0;
    q[0] = root;
    deepth[0] = 0;
    deepth[root] = 1;
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t];~i;i = ne[i]){
            int j = e[i];
            if(deepth[j] > deepth[t] + 1){
                deepth[j] = deepth[t] + 1;
                f[j][0] = t;
                q[++tt] = j;
                for(int k = 1;k <= 15;k++){
                    f[j][k] = f[f[j][k - 1]][k - 1];
                }                                      
            }
        }
    }
}

int lca(int a,int b){
    if(deepth[a] < deepth[b])swap(a,b);
    for(int k = 15;k >= 0;k--){
        if(deepth[f[a][k]] >= deepth[b]){
            a = f[a][k];
        }
    }
    
    if(a == b)return a;
    
    for(int k = 15;k >= 0;k--){
        if(f[a][k] != f[b][k]){
            a = f[a][k];
            b = f[b][k];
        }
    }
    return f[a][0];
}

int main(){
    
    memset(h,-1,sizeof h);
    
    cin >> n;
    
    int root = -1;
    
    int a,b;
    
    for(int i = 0;i < n;i++){
        cin >> a >> b;
        if(b == -1){
            root = a;
        }else {
            add(a,b);
            add(b,a);
        }
    }
    
    bfs(root);
    
    //query
    cin >> m;
    
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        int res = lca(a,b);
        if(res == a)cout << 1 << endl;
        else if(res == b)cout << 2 << endl;
        else cout << 0 << endl;
    }
    return 0;
}