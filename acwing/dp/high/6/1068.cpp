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

const int N = 410,M = 1 << 18,MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m;
int g[N];
int f[N][N];
int d[N][N];

int main(){
    scanf("%d",&n);
    rep2(i,1,n){
        scanf("%d",&g[i]);
        g[i + n] = g[i];
    }
    rep1(i,1,2 * n)g[i] += g[i - 1];
    //区间dp,枚举区间的大小
    memset(f,0x3f,sizeof f);
    memset(d,-0x3f,sizeof d);
    rep2(len,1,n){
        rep2(l,1,n * 2){
            int r = l + len - 1;
            if(r > 2 * n)continue;
            if(l == r)f[l][r] = 0,d[l][r] = 0;
            else {
                rep1(k,l,r){
                    f[l][r] = min(f[l][r],f[l][k] + f[k + 1][r] + g[r] - g[l - 1]);
                    d[l][r] = max(d[l][r],d[l][k] + d[k + 1][r] + g[r] - g[l - 1]);
                }
            }
        }
    }
    int res = INF;
    rep2(i,1,n){
        res = min(res,f[i][i + n - 1]);
    }
    int ret = -INF;
    rep2(i,1,n)
        ret = max(ret,d[i][i + n - 1]);
    printf("%d\n%d\n",res,ret);

    return 0;
}