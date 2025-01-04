//dfs

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;


int n;
int p[N];
int w[5][N];

int f(){
    
    int res = 0;
    
    for(int i = 0;i + 1 < n;i++){
        if(p[i + 1] != p[i] + 1)res++;
    }
    
    return (res + 2) / 3;
    
}

bool check(){
    
    for(int i = 0;i + 1 < n;i++){
        
        if(p[i + 1] != p[i] + 1)return false;
        
    }
    return true;
}

bool dfs(int dep,int max_dep){
    
    if(dep + f() > max_dep)return false;
    
    if(check())return true;
    
    for(int len = 1;len <= n;len++){
        
        for(int l = 0;l + len - 1 < n;l++){
            
            int r = l + len - 1;
            
            for(int k = r + 1;k < n;k++){
                
                memcpy(w[dep],p,sizeof p);
                
                int x = l,y = r + 1;
                
                for(x = l,y = r + 1;y <= k;x++,y++)p[x] = w[dep][y];
                
                for(y = l;y <= r;x++,y++)p[x] = w[dep][y];
                
                if(dfs(dep + 1,max_dep))return true;
                
                memcpy(p,w[dep],sizeof p);
            }
        }
    }
    return false;
}

void solve(){
    
    cin >> n;
    
    for(int i = 0;i < n;i++)cin >> p[i];
    
    int deep_v = 0;
    
    while(deep_v < 5 && !dfs(0,deep_v))deep_v++;
    
    if(deep_v >= 5)cout << "5 or more" << endl;
    else cout << deep_v << endl;
}

int main(){
    
    int t;cin >> t;
    while(t--)solve();
    
    return 0;
}