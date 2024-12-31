//bfs

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010,M = N * 2;

int n,m;
int q[M];
int d[M];

int bfs(){
    
    int hh = 0,tt = 0;
    
    memset(d,-1,sizeof d);
    
    q[0] = n;
    d[n] = 0;
    while(hh <= tt){
        
        int u = q[hh++];
        
        if(u == m)return d[u];
        
        if(u + 1 < N && d[u + 1] == -1){
            q[++tt] = u + 1;
            d[u + 1] = d[u] + 1; 
        }
        
        if(u - 1 < M && d[u - 1] == -1){
            q[++tt] = u - 1;
            d[u - 1] = d[u] + 1;
        }
        
        if(u * 2 < M && d[u * 2] == -1){
            q[++tt] = u * 2;
            d[u * 2] = d[u] + 1;
        }
        
    }
    return -1;
}

int main(){
    
    cin >> n >> m;
    
    cout << bfs() << endl;
    
    return 0;
    
}