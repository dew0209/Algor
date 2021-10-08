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

const int N = 35,M = 22,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m;
int f[N][10];


void init(){
    rep1(i,0,10)f[1][i] = 1;
    rep1(i,2,N)
        rep1(j,0,10)
            rep1(k,0,10){
                if(abs(j - k) >= 2)f[i][j] += f[i - 1][k];
            }
}

int solve(int u){
    if(!u)return 0;
    VI nums;
    while(u)nums.pb(u % 10),u /= 10;
    int ans = nums.size();
    int last = -2;
    int res = 0;
    rep2(i,ans - 1,0){
        int x = nums[i];
        rep1(j,0,x){
            if(i == ans - 1 && j == 0)continue;
            if(abs(j - last) >= 2)res += f[i + 1][j];
        }
        if(abs(x - last) < 2)break;
        last = x;
        if(!i)res++;
    }
    //处理低位
    rep1(i,1,ans){
        rep1(j,1,10)
            res += f[i][j];
    }
    return res;
}

int main(){
    init();
    scanf("%d%d",&n,&m);
    printf("%d",solve(m) - solve(n - 1));

    return 0;
}