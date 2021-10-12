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
LL a[N],b[N];
LL sum[N];
int q[N];
bool st[N];

int main(){
    //读入所有的车站
    scanf("%d",&n);
    rep1(i,1,n + 1){
        scanf("%d %d",&b[i],&a[i]);
        a[i + n] = a[i];
        b[i + n] = b[i];
    }

    rep1(i,1,2 * n + 1){
        sum[i] = b[i] - a[i];
        sum[i] += sum[i - 1];
    }
    int hh = 0,tt = -1;
    //顺时针
    rep2(i,2 * n,1){
        //维护队头
        if(hh <= tt && q[hh] > i + n - 1)hh++;
        //插入
        while (hh <= tt && sum[q[tt]] >= sum[i])tt--;
        q[++tt] = i;
        if(i <= n && sum[q[hh]] - sum[i - 1] >= 0)st[i] = true;
    }
    //逆时针
    hh = 0,tt = -1;
    mf1(sum);
    a[0] = a[n];
    rep2(i,2 * n,1){
        sum[i] = b[i] - a[i - 1];
        sum[i] += sum[i + 1];
    }
    rep1(i,1,2 * n + 1){
        if(hh <= tt && q[hh] < i - n + 1)hh++;
        while (hh <= tt && sum[q[tt]] >= sum[i])tt--;
        q[++tt] = i;
        if(i > n && sum[q[hh]] - sum[i + 1] >= 0)st[i - n] = true;
    }
    rep1(i,1,n + 1){
        if(st[i]){
            printf("TAK\n");
        }else printf("NIE\n");
    }

    return 0;
}