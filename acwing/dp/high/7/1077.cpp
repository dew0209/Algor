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
int f[N][3];
bool st[N];

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void dfs(int u){
    f[u][2] = w[u];
    int sum = 0;
    repx(i,u){
        int j = e[i];
        dfs(j);
        f[u][0] += min(f[j][1],f[j][2]);
        f[u][2] += min(f[j][0],min(f[j][1],f[j][2]));
        sum += min(f[j][1],f[j][2]);
    }
    f[u][1] = INF;
    repx(i,u){
        int j = e[i];
        f[u][1] = min(f[u][1],sum - min(f[j][1],f[j][2]) + f[j][2]);
    }
}

int main(){
    scanf("%d",&n);
    mf(h);
    rep1(i,0,n){
        int id;scanf("%d",&id);
        scanf("%d",&w[id]);
        scanf("%d",&m);
        rep1(j,0,m){
            int c;scanf("%d",&c);
            add(id,c);
            st[c] = true;
        }
    }
    int root = 1;
    while (st[root])root++;//find root
    dfs(root);
    printf("%d",min(f[root][1],f[root][2]));
    return 0;
}