//bfs

#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

typedef pair<int,int> PII;

#define fi first
#define se second

const int N = 510;

int n,m;

string g[N];
int dist[N][N];
bool st[N][N];

int dx[] = {-1,-1,1,1},dy[] = {-1,1,1,-1};
int ix[] = {-1,-1,0,0},iy[] = {-1,0,0,-1};

int bfs(){
    
    deque<PII> q;
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);

    char cs[] = "\\/\\/";
    
    q.push_front({0,0});
    dist[0][0] = 0;
    
    while(!q.empty()){
        
        auto u = q.front();
        q.pop_front();
        
        int x = u.fi,y = u.se;
        
        if(st[x][y])continue;
        st[x][y] = true;
        
        for(int i = 0;i < 4;i++){
            
            int ax = dx[i] + x;
            int ay = dy[i] + y;
            if(ax < 0 || ax > n || ay < 0 || ay > m)continue;
            
            int bx = ix[i] + x;
            int by = iy[i] + y;
            
            int distance = (g[bx][by] != cs[i]) + dist[x][y];
            
            if(distance < dist[ax][ay]){
                
                dist[ax][ay] = distance;
                
                
                if(g[bx][by] == cs[i]){
                    q.push_front({ax,ay});
                }else {
                    q.push_back({ax,ay});
                }
            }
        }
    }
    return dist[n][m];
}

int main(){
    int t;cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0;i < n;i++)cin >> g[i];
        int res = bfs();
        
        if(res >= 0x3f3f3f3f / 2)cout << "NO SOLUTION" << endl;
        else {
            cout << res << endl;
        }
        
    }
    
    return 0;
}