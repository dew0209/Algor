#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

#define pb  push_back
#define fi first
#define se second
#define rep1(c,a,b) for(int c = a;c < b;++c)
#define rep2(c,a,b) for(int c = a;c <= b;++c)

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

const int N = 18,M = 1 << 18,MOD18 = 1e8;
const double eps = 1e-8;

int n,m;
PDD q[N];
int path[N][N];
int f[M];

int cmp(double x,double y){
    if(fabs(x - y) < eps)return 0;
    if(x < y)return -1;
    return 1;
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        rep1(i,0,n)scanf("%lf%lf",&q[i].fi,&q[i].se);
        memset(path,0,sizeof path);
        rep1(i,0,n){
            path[i][i] = 1 << i;
            rep1(j,0,n){
                double x1 = q[i].fi,y1 = q[i].se;
                double x2 = q[j].fi,y2 = q[j].se;
                if(!cmp(x1,x2))continue;
                double a = (y1 / x1 - y2 / x2) / (x1 - x2);
                double b = y1 / x1 - a * x1;
                if(cmp(a,0) >= 0)continue;
                int state = 0;
                rep1(k,0,n){
                    double x = q[k].fi,y = q[k].se;
                    if(!cmp(a * x * x + b * x,y))state += 1 << k;
                }
                path[i][j] = state;
            }
        }
        memset(f,0x3f,sizeof f);
        f[0] = 0;
        rep1(i,0,(1 << n) - 1){
            int x = 0;
            for(int j = 0;j < n;j++){
                if(!(i >> j & 1)){
                    x = j;
                    break;
                }
            }
            rep1(j,0,n){
                f[i | path[x][j]] = min(f[i | path[x][j]],f[i] + 1);
            }
        }
        printf("%d\n",f[(1 << n) - 1]);
    }

    return 0;
}