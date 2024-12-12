//dp

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

#define fi first
#define se second

using namespace std;

typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef long long LL;

const int N = 20,M = 1 << 20;
const double eps = 1e-8;

int n,m;
int f[M];
PDD g[N];
int h[N][N];

int cmp(double x,double y){
    if(fabs(x - y) < eps)return 0;
    if(x < y)return -1;
    return 1;
}

void solve(){
    
    cin >> n >> m;
    
    for(int i = 0;i < n;i++){
        cin >> g[i].fi >> g[i].se;
    }
    memset(h,0,sizeof h);

    for(int i = 0;i < n;i++){
        h[i][i] = 1 << i;
        for(int j = 0;j < n;j++){
            double x1 = g[i].fi,y1 = g[i].se;
            double x2 = g[j].fi,y2 = g[j].se;
            if(!cmp(x1,x2))continue;
            
            double a = (y1 * x2 - y2 * x1) / (x1 - x2) / (x1 * x2);
            double b = (y1 - a * x1 * x1) / x1;
            
            if(cmp(a,0) >= 0)continue;
            
            int state = 0;
            for(int k = 0;k < n;k++){
                double x = g[k].fi,y = g[k].se;
                if(!cmp(y,a * x * x + b * x)){
                    state += 1 << k;
                }
            }
            h[i][j] = state;
        }
    }
    
    memset(f,0x3f,sizeof f);
    f[0] = 0;
    for(int i = 0;i < 1 << n;i++){
        int x = 0;
        for(int j = 0;j < n;j++){
            if(!((i >> j) & 1)){
                x = j;
                break;
            }
        }
        for(int j = 0;j < n;j++){
            f[i | h[x][j]] = min(f[i | h[x][j]],f[i] + 1);
        }
    }
    cout << f[(1 << n) - 1] << endl;
}

int main(){
    
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}