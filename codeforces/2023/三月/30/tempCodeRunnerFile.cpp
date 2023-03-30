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
 
const int N = 200010,M = 200010;

LL n,m;
LL q[N];

LL get_res(LL x){
    int l = 0,r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(x <= q[mid])r = mid;
        else l = mid + 1;
    }
    return l;
}


int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%lld",&q[i]);
    }
    q[n] = 0x3f3f3f3f;
    LL sum = 0;
    for(int i = 0;i < n;i++){
        sum += q[i];
    }
    sort(q,q + n);
    scanf("%lld",&m);
    while(m--){
        LL x,y;
        scanf("%lld%lld",&x,&y);
        int idx = get_res(x);
        LL res = 0x3f3f3f3f;
        if(idx > 0)res = min(res,(x - q[idx - 1]) + max(0LL,y - sum + q[idx - 1]));
        if(idx < n)res = min(res,max(0LL,y - sum + q[idx]));
        printf("%lld\n",res);
    }
}