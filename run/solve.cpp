#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long LL;

#define pb  push_back
#define fi first
#define se second
#define rep1(c,a,b) for(int c = a;c < b;++c)
#define rep2(c,a,b) for(int c = a;c <= b;++c)
#define repx(a,b) for(int a = h[b];~a;a = ne[a])
#define mf(h) memset(h,-1,sizeof h);
#define ALL(a) a.begin(),a.end()

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

const int N = 50,M = N * 2,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m;
LL f[N][N];
LL g[N];

int main(){
    scanf("%d",&n);
    rep2(i,1,n)scanf("%d",g[i]);
    rep2(len,1,n){
        rep2(l,1,l + len - 1){
            int r = l + len - 1;
            rep2(k,l + 1,r - 1){
                f[l][r] = max(f[l][r],f[l][r] + f[r + 1][r] + g[l] * g[k] * g[k + 1]);
            }
        }
    }
    printf("%d\n",f[1][n]);

    return 0;
}