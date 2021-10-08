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

const int N = 210,M = 1 << 18,MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m;
int g[N];
int f[N][N];

int main(){
    scanf("%d",&n);
    rep2(i,1,n){
        scanf("%d",&g[i]);
        g[i + n] = g[i];
    }
    memset(f,-0x3f,sizeof f);
    rep2(len,2,n + 1){
        rep2(l,1,n * 2){
            int r = l + len - 1;
            if(r > 2 * n)continue;
            if(len == 2)f[l][r] = 0;
            else {
                rep1(k,l + 1,r){
                    f[l][r] = max(f[l][r],f[l][k] + f[k][r] + g[l] * g[k] * g[r]);
                }
            }

        }
    }
    int ret = -INF;
    rep2(i,1,n)ret = max(ret,f[i][i + n]);
    printf("%d",ret);
    return 0;
}