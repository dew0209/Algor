//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110,M = N * N;

int n,m;
int h[N],e[M],ne[M],idx;
int stk[N],top;
int dfn[N],low[N];
bool in_stk[N];
int scc_cnt,scc_size[N];
int id[N];
int din[N],dout[N];
int timestamp;

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}


void tartjin(int u){
    
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u,in_stk[u] = true;
    
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tartjin(j);
            low[u] = min(low[u],low[j]);
        }else if(in_stk[j]){
            low[u] = min(low[u],dfn[j]);
        }
    }
    
    if(dfn[u] == low[u]){
        ++scc_cnt;
        int y;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            scc_size[scc_cnt]++;
        }while(y != u);
    }
}


int main(){
    
    memset(h,-1,sizeof h);
    cin >> n;
    
    for(int i = 1;i <= n;i++){
        int a;
        while(cin >> a,a){
            add(i,a);
        }
    }
    for(int i = 1;i <= n;i++){
        if(!dfn[i]){
            tartjin(i);
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = h[i];~j;j = ne[j]){
            int a = id[i],b = id[e[j]];
            if(a != b){
                din[b]++;
                dout[a]++;
            }
        }
    }
    
    int dinsum = 0,doutsum = 0;
    
    for(int i = 1;i <= scc_cnt;i++){
        
        if(!din[i]){
            dinsum++;
        }
        
        if(!dout[i]){
            doutsum++;
        }
        
    }
    
    cout << dinsum << endl;
    
    if(scc_cnt == 1)cout << 0 << endl;
    else cout << max(dinsum,doutsum) << endl;
    return 0;
}