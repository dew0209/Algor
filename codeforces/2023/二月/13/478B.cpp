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

LL get(LL n,LL m){
    LL res = 1;
    for(LL i = n;i >= n - m + 1;i--){
        res = res * i;
    }
    for(LL i = 1;i <= m;i++){
        res /= i;
    }
    return res;
}

int main(){
    LL n,m;
    scanf("%lld%lld",&n,&m);
    LL d = n / m;
    LL diff = n - d * m;
    LL minv = get(d + 1,2) * diff + get(d,2) * (m - diff);
    LL maxv = get(n - (m - 1),2);
    printf("%lld %lld\n",minv,maxv);
    return 0;
}