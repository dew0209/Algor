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
#define mfx(h) memset(h,-1,sizeof h);
#define mf1(h) memset(h,0,sizeof h);
#define mf2(h) memset(h,0x3f,sizeof h);
#define mf3(h) memset(h,-ox3f,sizeof h);
#define ALL(a) a.begin(),a.end()

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

template <class T> T mod(T a,T b){return (a % b + b) % b;}

const int N = 10,M = 22,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

double X;
int n,m,p;
double f[N][N][N][N][M];
int s[M][M];

int get_sum(int x1,int y1,int x2,int y2){
    return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
}

double get(int x1,int y1,int x2,int y2){
    double sum = get_sum(x1,y1,x2,y2) - X;
    return (double)sum * sum / n;
}

double dp(int x1,int y1,int x2,int y2,int k){
    double& v = f[x1][y1][x2][y2][k];
    if(v >= 0)return v;
    if (k == 1)return v = get(x1,y1,x2,y2);
    v = INF;
    rep1(i,x1,x2){
        v = min(v,get(x1,y1,i,y2) + dp(i + 1,y1,x2,y2,k - 1));
        v = min(v,dp(x1,y1,i,y2,k - 1) + get(i + 1,y1,x2,y2));
    }
    rep1(i,y1,y2){
        v = min(v,get(x1,y1,x2,i) + dp(x1,i + 1,x2,y2,k - 1));
        v = min(v,get(x1,i + 1,x2,y2) + dp(x1,y1,x2,i,k - 1));
    }
    return v;
}

int main(){
    m = 8;
    scanf("%d",&n);
    rep1(i,1,m + 1)
        rep1(j,1,m + 1) {
            scanf("%d", &s[i][j]);
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    X = (double)s[m][m] / n;
    mfx(f);
    printf("%.3f",sqrt(dp(1,1,8,8,n)));
    return 0;
}