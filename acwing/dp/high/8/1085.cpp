#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long LL;

#define pb  push_back
#define fi first
#define se second
#define rep1(c,a,b) for(int c = a;c < b;++c)
#define rep2(c,a,b) for(int c = a;c >= b;--c)
#define repx(a,b) for(int a = h[b];~a;a = ne[a])
#define mf(h) memset(h,-1,sizeof h);
#define ALL(a) a.begin(),a.end()

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

const int N = 15,M = 22,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m;
int f[N][10];

void init(){
    rep1(i,0,10)f[1][i] = 1;
    f[1][4] = 0;
    rep1(i,2,N)
        rep1(j,0,10)
            rep1(k,0,10){
                if(j == 4 || k == 4)continue;
                if(j == 6 && k == 2)continue;
                f[i][j] += f[i - 1][k];
            }
}

int solve(int u){
    if(!u)return 1;
    VI nums;
    while (u)nums.pb(u % 10),u /= 10;
    int res = 0;
    int last = 0;
    int ans = nums.size();
    rep2(i,ans - 1,0){
        int x = nums[i];
        rep1(j,0,x){
            if(j == 4)continue;
            if(last == 6 && j == 2)continue;
            res += f[i + 1][j];
        }
        if(x == 4)break;
        if(last == 6 && x == 2)break;
        last = x;
        if(!i)res++;
    }
    return res;
}

int main(){
    init();
    while(cin >> n >> m,n || m)
        printf("%d\n",solve(m) - solve(n - 1));

    return 0;
}