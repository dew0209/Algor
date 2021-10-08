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

const int N = 1510,M = N * 2,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m;
int h[N],e[M],ne[M],w[M],idx;
int f[N][2];

void add(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}

void dfs(int u,int fa){
    f[u][1] = 1;
    f[u][0] = 0;
    repx(i,u){
        int j = e[i];
        if(j == fa)continue;
        dfs(j,u);
        f[u][0] += f[j][1];
        f[u][1] += min(f[j][0],f[j][1]);
    }
}

int main(){
    while(scanf("%d",&n) == 1){
        //printf("%d",n);
        mf(h);
        idx = 0;
        rep1(i,0,n){
            int id,cnt;
            scanf("%d:(%d)",&id,&cnt);
            id++;
            rep2(j,1,cnt){
                int v;scanf("%d",&v);
                v++;
                add(id,v,1);
                add(v,id,1);
            }
        }
        dfs(1,-1);

        printf("%d\n",min(f[1][0],f[1][1]));
    }
    return 0;
}