#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 200010;

int n;
LL q[N];
map<LL,LL> cnt;

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
        cnt[q[i]]++;
    }
    sort(q + 1,q + n + 1);
    LL ans = 0;
    if(q[1] == q[n]){
        ans = cnt[q[n]] * (cnt[q[n]] - 1) / 2;
    }else {
        ans = cnt[q[n]] * cnt[q[1]];
    }
    int res = q[n] - q[1];
    printf("%d %lld\n",res,cnt[q[1]] * 1LL * cnt[q[n]]);
    return 0;
}