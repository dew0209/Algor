//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5010,M = N * 2;

int n,m;
int h[N],e[M],ne[M],idx;
int dfn[N],low[N],timestamp;
int stk[N],top;
int id[N],dcc_cnt;
bool is_bridge[M];
int d[N];

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void tarjan(int u,int from){
    
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    
    for(int i = h[u];~i;i = ne[i]){
        
        int j = e[i];
        
        if(!dfn[j]){
            tarjan(j,i);
            low[u] = min(low[u],low[j]);
            if(dfn[u] < low[j]){
                is_bridge[i] = is_bridge[i ^ 1] = true;
            }
        }else if(i != (from ^ 1)){
            low[u] = min(low[u],dfn[j]);
        }
    }
    
    if(dfn[u] == low[u]){
        ++dcc_cnt;
        int y;
        do{
            y = stk[top--];
            id[y] = dcc_cnt;
        }while(y != u);
    }
    
}

int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    
    for(int i = 0;i < m;i++){
        int a,b;cin >> a >> b;
        add(a,b);add(b,a);
    }
    
    tarjan(1,-1);
    
    for(int i = 0;i < idx;i++){
        if(is_bridge[i]){
            d[id[e[i]]]++;
        }
    }
    
    int cnt = 0;
    for(int i = 1;i <= dcc_cnt;i++){
        if(d[i] == 1){
            cnt++;
        }
    }
    
    printf("%d\n",(cnt + 1) / 2);
    return 0;
}
