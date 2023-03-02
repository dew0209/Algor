#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 300010,MOD = 1e9 + 7;

int n,m;
int q[2][N];

void solve(){
    scanf("%d",&n);
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&q[i][j]);
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0;i < n;i++){
        sum1 += q[0][i];
    }
    int res = MOD;
    for(int i = 0;i < n;i++){
        sum1 -= q[0][i];
        res = min(res,max(sum1,sum2));
        sum2 += q[1][i];
    }
    printf("%d",res);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}