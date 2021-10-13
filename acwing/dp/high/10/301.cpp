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

const int N = 300010,M = N * 2,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f,MOD = 998244353;
const double eps = 1e-8;

int n,s;
LL c[N],t[N];
LL f[N];
int q[N];

int main(){
    scanf("%d%d",&n,&s);
    rep1(i,1,n + 1){
        scanf("%lld%lld",&t[i],&c[i]);
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }
    mf2(f);
    f[0] = 0;
    int hh = 0,tt = 0;
    rep1(i,1,n + 1){
        while (hh < tt && (f[q[hh + 1]] - f[q[hh]]) <= (t[i] + s) * (c[q[hh + 1]] - c[q[hh]]))hh++;
        int j = q[hh];
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];
        while (hh < tt && (f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt - 1]]) >= (f[i] - f[q[tt - 1]]) * (c[q[tt]] - c[q[tt - 1]]))tt--;
        q[++tt] = i;
    }


    printf("%lld\n",f[n]);
    return 0;
}