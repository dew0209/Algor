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

const int N = 10010,M = N * 2,MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m;
int h[N],e[M],ne[M],w[M],idx;
int res = -INF;

int dfs(int u,int fa){
    //不是d1 = -INF,d2 = -INF 注意哦
    int d1 = 0,d2 = 0;
    repx(i,u){
        int j = e[i];
        if(j == fa)continue;
        int v = dfs(j,u) + w[i];
        if(v > d1){
            d2 = d1;
            d1 = v;
        } else if(v > d2){
            d2 = v;
        }
    }
    res = max(res,d1 + d2);
    return d1;
}

void add(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}

int main(){
    scanf("%d",&n);
    mf(h);
    rep1(i,1,n){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,-1);
    printf("%d",res);
    return 0;
}