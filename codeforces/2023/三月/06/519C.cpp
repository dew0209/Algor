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

int n,m;
int q[N];

int main(){
    scanf("%d%d",&n,&m);
    int res = 0;
    for(int i = 0;i <= n;i++){
        int cur = i;
        int lf = n - i;
        int rf = m - 2 * i;
        if(rf >= 0){
            cur += min(rf,lf / 2);
            res = max(res,cur);
        }
    }
    printf("%d\n",res);
    return 0;
}