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

const int N = 200010,MOD = 1e9 + 7;

LL q[10];

int main(){
    LL x,y,n;
    scanf("%lld%lld%lld",&x,&y,&n);
    q[0] = x;
    q[1] = y;
    n--;
    for(int i = 2;i < 6;i++){
        q[i] = q[i - 1] - q[i - 2];
    }
    int r = n % 6;

    printf("%lld\n",(q[r] % MOD + MOD) % MOD);
    return 0;
}