//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110,INF = 0x3f3f3f3f;

int n,m;
int g[N][N];
int w[N][N];
int level[N];
int dist[N];
bool st[N];

int dijkstr(int down,int up){
    memset(dist,0x3f,sizeof dist);
    memset(st,false,sizeof st);
    dist[0] = 0;
    
    for(int i = 0;i <= n;i++){
        
        int t = -1;
        
        for(int j = 0;j <= n;j++){
            
            if(!st[j] && (t == -1 || dist[j] < dist[t])){
                t = j;
            }
        }
        
        st[t] = true;
        
        
        for(int j = 0;j <= n;j++){
            
            if(level[j] >= down && level[j] <= up){
                dist[j] = min(dist[j],dist[t] + w[t][j]);
            }
        }
        
    }
    return dist[1];
}

int main(){
    
    memset(w,0x3f,sizeof w);

    
    cin >> m >> n;
    
    for(int i = 1;i <= n;i++){
        
        int p,l,x;cin >> p >> l >> x;
        w[0][i] = p;
        level[i] = l;
        
        while(x--){
            
            int t,v;
            
            cin >> t >> v;
            
            w[t][i] = v;
        }
    }
    
    int res = INF;
    
    for(int i = level[1] - m;i <= level[1];i++){
        
        res = min(res,dijkstr(i,i + m));
        
    }
    
    cout << res << endl;
    return 0;
}