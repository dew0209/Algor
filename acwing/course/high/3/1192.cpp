//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010,M = N * 2;

int n,m;
int h[N],e[M],ne[M],idx;
int d[N];
int q[N];
int dist[N];

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool topsort(){
    
    int hh = 0,tt = -1;
    
    for(int i = 1;i <= n;i++){
        
        if(d[i] == 0){
            q[++tt] = i;
        }
    }
    
    while(hh <= tt){
        
        int t = q[hh++];
        
        for(int i = h[t];~i;i = ne[i]){
            
            int j = e[i];
            
            d[j]--;
            
            if(d[j] == 0){
                q[++tt] = j;
            }
        }
    }
    return tt == n - 1;
}

int main(){
    
    memset(h,-1,sizeof h);
    
    cin >> n >> m;
    
    for(int i = 1;i <= m;i++){
        int a,b;cin >> a >> b;
        add(b,a);
        d[a]++;
    }
    
    if(!topsort())cout << "Poor Xed" << endl;
    else {
        
        for(int i = 1;i <= n;i++)dist[i] = 100;
        
        for(int i = 0;i < n;i++){
            int j = q[i];
            for(int k = h[j];~k;k = ne[k]){
                int t = e[k];
                dist[t] = max(dist[j] + 1,dist[t]);
            }
        }
        
        int res = 0;
        
        for(int i = 1;i <= n;i++){
            res += dist[i];
        }
        cout << res << endl;
    }
    return 0;
}