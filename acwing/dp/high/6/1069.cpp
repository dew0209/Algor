#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long LL;

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

const int N = 55,M = 35,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m;
LL f[N][N][M];
LL g[N];

void mul(LL a[],LL b){
    LL c[M];
    memset(c,0,sizeof c);
    LL t = 0;
    for(int i = 0;i < M;i++){
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a,c,sizeof c);
}

void add(LL a[],LL b[]){
    LL c[M];
    memset(c,0,sizeof c);
    int t = 0;
    for(int i = 0;i < M;i++){
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a,c,sizeof c);
}

int cmp(LL a[],LL b[]){
    for(int i = M - 1;i >= 0;i--){
        if(a[i] > b[i])return 1;
        else if(a[i] < b[i])return -1;
    }
    return 0;
}

void print(LL a[]){
    int k = M - 1;
    while(k && !a[k])k--;
    while(k >= 0)printf("%d",a[k--]);
    puts("");
}

int main(){
    scanf("%d",&n);
    LL temp[M];
    rep2(i,1,n)scanf("%d",&g[i]);
    rep2(len,3,n){
        rep2(l,1,n){
            int r = l + len - 1;
            if(r > n)continue;
            f[l][r][M - 1] = 1;
            rep2(k,l + 1,r - 1){
                memset(temp,0,sizeof temp);
                temp[0] = g[l];
                mul(temp,g[k]);//相乘
                mul(temp,g[r]);
                add(temp,f[l][k]);//相加
                add(temp,f[k][r]);
                if(cmp(f[l][r],temp) > 0){
                    memcpy(f[l][r],temp,sizeof temp);
                }
            }
        }
    }
    print(f[1][n]);

    return 0;
}