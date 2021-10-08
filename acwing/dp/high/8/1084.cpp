#include <cstdio>
#include <vector>
#include <algorithm>
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
#define mf3(h) memset(h,-0x3f,sizeof h);
#define ALL(a) a.begin(),a.end()

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

template <class T> T mod(T a,T b){return (a % b + b) % b;}

const int N = 110,M = 22,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m,p;
int f[N][10][N];

void init(){
    mf1(f);
    rep1(i,0,10)f[1][i][i % p] = 1;
    rep1(i,2,N)
        rep1(j,0,10)
            rep1(k,0,p)
                rep1(x,0,10)
                    f[i][j][k] += f[i - 1][x][mod(k - j,p)];
}

int solve(int u){
    if(!u)return 1;
    VI nums;
    while (u)nums.pb(u % 10),u /= 10;
    int ans = nums.size();
    int res = 0;
    int last = 0;
    rep2(i,ans - 1,0){
        int x = nums[i];
        rep1(j,0,x){
            res += f[i + 1][j][mod(-last,p)];
        }
        last += x;
        if(!i && last % p == 0)res++;
    }
    return res;
}

int main(){
    while (cin >> n >> m >> p){
        init();
        printf("%d\n",solve(m) - solve(n - 1));
    }

    return 0;
}