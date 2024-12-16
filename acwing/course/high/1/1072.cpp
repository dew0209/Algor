//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010,M = N * 2;

int n,m;
int h[N],e[M],ne[M],w[M],idx;
int ans = 0;

void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs(int u,int fa){
    
    int d1 = 0,d2 = 0;
    
    for(int i = h[u];~i;i = ne[i]){
        
        int j = e[i];
        
        if(j != fa){
            
            int d = bfs(j,u) + w[i];
            
            if(d > d1){
                d2 = d1;
                d1 = d;
            }else if(d > d2){
                d2 = d;
            }
        }
    }
    
    ans = max(d1 + d2,ans);
    return d1;
}


int main(){
    
    cin >> n;
    
    memset(h,-1,sizeof h);
    
    for(int i = 0;i < n - 1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    
    bfs(1,-1);
    
    cout << ans << endl;
    
    return 0;
    
}