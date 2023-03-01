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

LL a,b,n,m;

void solve(){
    scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
    if(m <= min(a,b) && a + b >= n + m){
        printf("Yes");
    }else {
        printf("No");
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}