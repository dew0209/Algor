#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;

const int N = 300010;

int n,m;
LL f[N][2];
int q[N];

void solve(){
    scanf("%d%d",&n,&m);
    memset(f,0,sizeof f);
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
    }
    f[0][0] = 0;
    f[0][1] = 0;
    for(int i = 1;i <= n;i++){
        f[i][0] = max(f[i - 1][0],f[i - 1][1] + q[i]);
        f[i][1] = max(f[i - 1][1],f[i - 1][0] - q[i]);
    }
    printf("%lld",max(f[n][0],f[n][1]));
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}