//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;

int n;
int w[N][N];
int dist[N];
bool st[N];

int prim(){
    
    memset(dist,0x3f,sizeof dist);
    dist[0] = 0;
    
    int res = 0;
    for(int i = 0;i <= n;i++){
        int t = -1;
        for(int j = 0;j <= n;j++){
            if(!st[j] && (t == -1 || dist[j] < dist[t])){
                t = j;
            }
        }
        res += dist[t];
        st[t] = true;
        for(int j = 0;j <= n;j++){
            dist[j] = min(dist[j],w[j][t]);
        }
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        int v;cin >> v;
        w[i][0] = w[0][i] = v;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> w[i][j];
        }
    }
    
    int res = prim();
    
    cout << res << endl;
    return 0;
}