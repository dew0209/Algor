#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iostream>

using namespace std;

#define pb  push_back
#define fi first
#define se second
#define rep1(c,a,b) for(int c = a;c < b;++c)
#define rep2(c,a,b) for(int c = a;c >= b;--c)
#define repx(a,b) for(int a = h[b];~a;a = ne[a])
#define mfx(h) memset(h,-1,sizeof h);
#define mf1(h) memset(h,0,sizeof h);
#define mf2(h) memset(h,0x3f,sizeof h);
#define mf3(h) memset(h,-ox3f,sizeof h);
#define ALL(a) a.begin(),a.end()

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;

template <class T> T mod(T a,T b){return (a % b + b) % b;}

const int N = 1010,M = N * 2,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f,MOD = 998244353;
const double eps = 1e-8;

int a,b,n;
int g[N][N];
int q[N];
int row_max[N][N],row_min[N][N];

void get_min(int d[],int e[],int to){
    int hh = 0,tt = -1;
    rep1(i,1,to + 1){
        if(hh <= tt && q[hh] <= i - n)hh++;
        while (hh <= tt && d[q[tt]] >= d[i])tt--;
        q[++tt] = i;
        e[i] = d[q[hh]];
    }
}

void get_max(int d[],int e[],int to){
    int hh = 0,tt = -1;
    rep1(i,1,to + 1){
        if(hh <= tt && q[hh] <= i - n)hh++;
        while (hh <= tt && d[q[tt]] <= d[i])tt--;
        q[++tt] = i;
        e[i] = d[q[hh]];
    }
}

int main(){
    scanf("%d%d%d",&a,&b,&n);
    rep1(i,1,a + 1)
        rep1(j,1,b + 1)scanf("%d",&g[i][j]);
    rep1(i,1,a + 1){
        get_max(g[i],row_max[i],b);
        get_min(g[i],row_min[i],b);
    }
    int res = INF;
    int d[N],e[N],f[N];
    rep1(i,n,b + 1){
        rep1(j,1,a + 1){
            d[j] = row_min[j][i];
        }
        get_min(d,e,a);
        rep1(j,1,a + 1){
            d[j] = row_max[j][i];
        }
        get_max(d,f,a);
        rep1(j,n,a + 1)res = min(res,f[j] - e[j]);
    }

    printf("%d",res);

    return 0;
}