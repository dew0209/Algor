//图论

#include <iostream>
#include <algorithm>
#include<sstream>
#include <cstring>

using namespace std;

const int N = 510;

int n,m;
int road[N][N];
int q[N];
int dist[N];

int bfs(){
    
    memset(dist,0x3f,sizeof dist);
    int hh = 0,tt = 0;
    q[0] = 1;
    dist[1] = 0;
    while(hh <= tt){
        int t = q[hh++];
        for(int i = 1;i <= n;i++){
            if(road[t][i] && dist[i] > dist[t] + 1){
                dist[i] = dist[t] + 1;
                q[++tt] = i;
            }
            
        }
        
    }
    return dist[n];
}

int main(){
    
    cin >> m >> n;
    
    
    string line;
    getline(cin, line);
    
    for(int i = 0;i < m;i++){
        
        getline(cin, line);
        stringstream scin(line);
        int cnt = 0, t, stop[N];
        while (scin >> t) stop[cnt++] = t;
        for (int i = 0; i < cnt; i++)
            for (int j = i + 1; j < cnt; j++)
                road[stop[i]][stop[j]] = true;
    }
    
    int r = bfs();
    
    if(r == 0x3f3f3f3f)cout << "NO" << endl;
    else cout << r - 1 << endl;
    return 0;
}