//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010,M = 600010;

int n,m;

int h[N],hs[N],e[M],ne[M],w[M],idx;

int dfn[N],low[N],timestamp;
int stk[N],top;
int id[N];
int scc_cnt,scc_size[N];
bool in_stk[N];

int dist[N];

void add(int h[],int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

void tarjan(int u){
    
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u,in_stk[u] = true;
    
    for(int i = h[u];~i;i = ne[i]){
        
        int j = e[i];
        
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u],low[j]);
        }else if(in_stk[j]){
            low[u] = min(low[u],dfn[j]);
        }
    }
    
    if(low[u] == dfn[u]){
        int y;
        ++scc_cnt;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            scc_size[scc_cnt]++;
        }while(y != u);
    }
    
}

int main(){
    
    cin >> n >> m;

    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof hs);

    for (int i = 1; i <= n; i ++ ) add(h, 0, i, 1);
    
    for(int i = 0;i < m;i++){
        
        int a,b,t;
        cin >> t >> a >> b;
        if (t == 1) add(h, b, a, 0), add(h, a, b, 0);
        else if (t == 2) add(h, a, b, 1);
        else if (t == 3) add(h, b, a, 0);
        else if (t == 4) add(h, b, a, 1);
        else add(h, a, b, 0);
    }
    
    tarjan(0);
    
    bool success = true;
    
    for(int i = 0;i <= n;i++){
        
        for(int j = h[i];~j;j = ne[j]){
            
            int k = e[j];
            
            int a = id[i],b = id[k];
            
            if(a == b){
                
                if(w[j] > 0){
                    success = false;
                    break;
                }
            }else add(hs,a,b,w[j]);
        }
        if(!success)break;
    }
    
    if(!success){
        cout << "-1" << endl;
    }else {
        
        for(int i = scc_cnt;i;i--){
            for(int j = hs[i];~j;j = ne[j]){
                int k = e[j];
                if(dist[k] < dist[i] + w[j]){
                    dist[k] = dist[i] + w[j];
                }
            }
        }
    
        LL res = 0;
        
        for(int i = 1;i <= scc_cnt;i++)res = res + 1LL * dist[i] * scc_size[i];
        
        cout << res << endl;
        
    }
    
    return 0;
}