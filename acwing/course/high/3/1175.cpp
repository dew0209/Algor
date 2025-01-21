//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 100010,M = 2000010;

typedef long long LL;


int n,m,mod;

int h[N],hs[N],e[M],ne[M],idx;

int dfn[N],low[N];
int ssc_cnt,ssc_size[N];
int id[N];
int stk[N],top;
bool in_stk[N];
int timestamp;

int f[N],g[N];

void add(int h[],int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void tarjin(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u,in_stk[u] = true;
    
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
        ++ssc_cnt;
        int y;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = ssc_cnt;
            ssc_size[ssc_cnt]++;
        }while(y != u);
    }
}

int main(){
    
    memset(h,-1,sizeof h);
    memset(hs,-1,sizeof h);
    
    cin >> n >> m >> mod;
    
    for(int i = 0;i < m;i++){
        int a,b;cin >> a >> b;    
        add(h,a,b);
    }
    
    for(int i = 1;i <= n;i++){
        if(!dfn[i]){
            tarjin(i);
        }
    }
    
    unordered_set<LL> cnt;
    
    for(int i = 1;i <= n;i++){
        
        for(int j = h[i];~j;j = ne[j]){
            
            int k = e[j];
            
            int a = id[i],b = id[k];
            
            if(a != b && !cnt.count(a * 1000000LL + b)){
                add(hs,a,b);
                cnt.insert(a * 1000000LL + b);
            }
        }
    }
    
    for(int i = ssc_cnt;i;i--){
        
        if(!f[i]){
            f[i] = ssc_size[i];
            g[i] = 1;
        }
        
        for(int j = hs[i];~j;j = ne[j]){
            
            int k = e[j];
            
            if(f[k] < f[i] + ssc_size[k]){
                f[k] = f[i] + ssc_size[k];
                g[k] = g[i];
            }else if(f[k] == f[i] + ssc_size[k]){
                g[k] = (g[k] + g[i]) % mod;
            }
        }
    }
    
    int maxf = 0,sum = 0;
    
    for(int i = 1;i <= ssc_cnt;i++){
        if(f[i] > maxf){
            maxf = f[i];
            sum = g[i];
        }else if(f[i] == maxf){
            sum = (sum + g[i]) % mod;
        }
    }
    
    cout << maxf << endl;
    cout << sum << endl;
    
    return 0;
}