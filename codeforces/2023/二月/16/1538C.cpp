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

const int N = 200010;

using namespace std;

int n,l,r;
int q[N];

LL get(int l,int r,int x){
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(q[mid] <= x)l = mid;
        else r = mid - 1;
    }
    return l;
}

void solve(){
    scanf("%d%d%d",&n,&l,&r);
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
    }
    sort(q + 1,q + n + 1);
    LL sum = 0;
    for(int i = 1;i <= n;i++){
        LL a = get(i,n,r - q[i]) - i;
        LL b = get(i,n,l - q[i] - 1) - i;
        sum += a;
        sum -= b;
    }
    printf("%lld",sum);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
}