//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 300700;

int n;
int h[N],e[N],ne[N],w[N],idx;

int st[N];
int f[N][2];

void dfs(int u){
    
    f[u][0] = 0;
    f[u][1] = 1;
    
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        dfs(j);
        f[u][0] += f[j][1];
        f[u][1] += min(f[j][1],f[j][0]);
    }
}

void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int main(){
    
    while(~scanf("%d",&n)){
        
        memset(h,-1,sizeof h);
        memset(st,0,sizeof st);
        idx = 0;
        
        for(int i = 1;i <= n;i++){
            
            int id,cnt;
            scanf("%d:(%d)",&id,&cnt);
            
            if(cnt){
                int v;
                for(int j = 0;j < cnt;j++){
                    cin >> v;
                    add(id,v);
                    st[v] = 1;
                }
            }
        }
        
        int root = 0;
        while(st[root])root++;
        
        dfs(root);
        
        printf("%d\n",min(f[root][0],f[root][1]));
    }
    
}