#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 500010,MOD = 1e9 + 7;

LL n,k;
int p[N];

void solve(){
    scanf("%lld%lld",&n,&k);
    for(int i = 0;i < n;i++){
        scanf("%d",&p[i]);
    }
    LL x = 0;
    LL pSum = p[0];
    for(int i = 1;i < n;i++){
        x = max(x,(100LL * p[i] - k * pSum + k - 1) / k);
        pSum = p[i] + pSum;
    }
    printf("%lld",x);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}