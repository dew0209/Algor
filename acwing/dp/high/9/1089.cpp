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

const int N = 2000000,M = N * 2,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f,MOD = 998244353;
const double eps = 1e-8;

int n,m;
int g[N];
int q[N];
int f[N];

int main(){
    scanf("%d%d",&n,&m);
    rep1(i,1,n + 1)scanf("%d",&g[i]);
    int hh = 0,tt = 0;
    rep1(i,1,n + 1){
        if(hh <= tt && q[hh] < i - m)hh++;
        f[i] = g[i] + f[q[hh]];
        while (hh <= tt && f[i] <= f[q[tt]])tt--;
        q[++tt] = i;
    }
    int res = INF;
    rep1(i,n - m + 1,n + 1)res = min(res,f[i]);
    printf("%d\n",res);
    return 0;
}