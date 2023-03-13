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

const int N = 21;

LL f[N];

int main(){
    int n;scanf("%d",&n);
    f[0] = 1;
    for(int i = 1;i <= N;i++){
        f[i] = f[i - 1] * i;
    }
    LL ans = f[n] / f[n / 2] / f[n / 2];
    ans *= f[n / 2 - 1];
    ans *= f[n / 2 - 1];
    ans /= 2;
    printf("%lld\n",ans);
}