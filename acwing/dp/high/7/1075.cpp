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

const int N = 100010,M = N * 2,MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m;
int h[N],e[M],ne[M],w[M],idx;
int down[N][2],p[N][2],up[N];
int sum[N / 2];
bool st[N];
int res;

int dfs_d(int u,int fa){
    st[u] = true;
    repx(i,u){
        int j = e[i];
        if(j == fa)continue;
        int v = dfs_d(j,u) + w[i];
        if(v > down[u][0]){
            down[u][1] = down[u][0];
            p[u][1] = p[u][0];
            down[u][0] = v;
            p[u][0] = j;
        } else if(v > down[u][1]){
            down[u][1] = v;
            p[u][1] = j;
        }
    }
    res = max(res,down[u][0] + down[u][1]);

    return down[u][0];
}

void add(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}

int main(){
    scanf("%d",&n);
    mf(h);
    //统计一个数的约束
    rep2(i,1,n)
        rep2(j,2,n / i)
            sum[i * j] += i;
    rep2(i,2,n){
        if(sum[i] < i){
            add(i,sum[i],1);
            add(sum[i],i,1);
            //printf("%d %d \n",sum[i],i);
        }
    }
    rep2(i,1,n){
        if(!st[i])dfs_d(i,-1);
    }

    printf("%d",res);
    return 0;
}