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

const int N = 5010,M = N * 2,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f,MOD = 998244353;
const double eps = 1e-8;

int n,s;
LL sc[N],st[N];
LL f[N];

int main(){
    scanf("%d%d",&n,&s);
    rep1(i,1,n + 1){
        scanf("%lld%lld",&st[i],&sc[i]);
        st[i] += st[i - 1];
        sc[i] += sc[i - 1];
    }
    mf2(f);
    f[0] = 0;
    rep1(i,1,n + 1){
        rep1(j,0,i){
            f[i] = min(f[i],f[j] + (sc[i] - sc[j]) * st[i] + s * (sc[n] - sc[j]));
        }
    }
    printf("%lld\n",f[n]);
    return 0;
}