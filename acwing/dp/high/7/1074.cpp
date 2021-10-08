#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

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

const int N = 110,M = N * 2,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m;
int h[N],e[M],ne[M],w[M],idx;
int f[N][K];

void add(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}

void dfs(int u,int fa){
    repx(i,u){
        int j = e[i];
        if(j == fa)continue;
        dfs(j,u);
        for(int t = m;t > 0;t--){
            for(int k = 0;k < t;k++){
                f[u][t] = max(f[u][t],f[u][t - k - 1] + f[j][k] + w[i]);
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    mf(h);
    rep1(i,1,n){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,-1);

    printf("%d\n",f[1][m]);
    return 0;
}