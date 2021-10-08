#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

#define pb  push_back
#define fi first
#define se second
#define rep1(c,a,b) for(int c = a;c < b;++c)
#define rep2(c,a,b) for(int c = a;c <= b;++c)
#define all(a) (a.begin(),a.end())

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

const int N = 210,M = 1 << 18,MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n;
int g[N];
int f[N][N];
int p[N][N];

void dfs(int l,int r){
    if(l > r)return;
    int k = p[l][r];
    printf("%d ",k);
    dfs(l,k - 1),dfs(k + 1,r);
}

int main(){
    scanf("%d",&n);
    rep2(i,1,n)scanf("%d",&g[i]);
    rep2(len,1,n){
        rep2(l,1,n){
            int r = l + len - 1;
            if(r > n)continue;
            if(len == 1)f[l][r] = g[l],p[l][r] = l;
            else {
                rep1(k,l,r){
                    int a = f[l][k - 1] == 0 ? 1 : f[l][k - 1];
                    int b = f[k + 1][r] == 0 ? 1 : f[k + 1][r];
                    int source = a * b + g[k];
                    if(source > f[l][r]){
                        f[l][r] = source;
                        p[l][r] = k;
                    }
                }
            }
        }
    }
    printf("%d\n",f[1][n]);
    dfs(1,n);

    return 0;
}