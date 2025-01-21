//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010,M = 50010;

int n,m;
int h[N],e[M],ne[M],idx;
int stk[M],top;
int id[N];
bool in_stk[M];
int timestamp;
int scc_size[N],scc_cnt;
int dfn[N],low[N];

int tol[N];

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void tarjin(int u){
    dfn[u] = low[u] = ++timestamp;
    in_stk[u] = true;
    stk[++top] = u;
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjin(j);
            low[u] = min(low[u],low[j]);
        }else if(in_stk[j]){
            low[u] = min(low[u],dfn[j]);
        }
    }
    if(dfn[u] == low[u]){
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
    memset(h,-1,sizeof h);
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b;cin >> a >> b;
        add(a,b);
    }
    for(int i = 1;i <= n;i++){
        if(!dfn[i]){
            tarjin(i);
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = h[i];~j;j = ne[j]){
            int a = i;
            int b = e[j];
            if(id[a] != id[b]){
                tol[id[a]]++;
            }
        }
    }
    int zeronum = 0,sum = 0;
    for(int i = 1;i <= scc_cnt;i++){
        if(!tol[i]){
            zeronum ++;
            sum += scc_size[i];
        }
        if(zeronum > 1){
            sum = 0;
            break;
        }
    }
    cout << sum << endl;
    return 0;
}