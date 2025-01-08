//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<double,double> PDD;

#define fi first
#define se second

const int N = 200,INF = 0x3f3f3f3f;

int n,m;
double dist[N][N];
char g[N][N];
double maxd[N];
PDD q[N];

double get_dist(int x,int y){
    
    double l = q[x].fi - q[y].fi;
    double r = q[x].se - q[y].se;
    return sqrt(l * l + r * r);
}


int main(){
    
    cin >> n;
    
    for(int i = 0;i < n;i++){
        cin >> q[i].fi >> q[i].se;
    }
    
    for(int i = 0;i < n;i++){
        cin >> g[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j)dist[i][j] = 0;
            else if(g[i][j] == '1')dist[i][j] = get_dist(i,j);
            else dist[i][j] = INF;
        }
    }
    
    for (int k = 0; k < n; k ++ )
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    
    double r1 = 0;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(dist[i][j] < INF / 2){
                maxd[i] = max(maxd[i],dist[i][j]);
            }
        }
        r1 = max(maxd[i],r1);
    }
    
    double r2 = INF;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(dist[i][j] > INF / 2){
                r2 = min(r2,maxd[i] + maxd[j] + get_dist(i,j));
            }
        }
    }
    printf("%.6lf\n",max(r1,r2));
    return 0;
}