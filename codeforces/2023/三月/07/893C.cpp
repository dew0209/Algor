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

typedef long long LL;

using namespace std;

const int N = 100010;

int n,m;
int q[N];
int f[N];

int find(int u){
    if(u != f[u])f[u] = find(f[u]);
    return f[u];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)f[i] = i;
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
    }
    while(m--){
        int l,r;scanf("%d%d",&l,&r);
        l = find(l),r = find(r);
        q[r] = min(q[r],q[l]);//只更新根节点就行了
        f[l] = r;
    }
    LL res = 0;
    for(int i = 1;i <= n;i++){
        if(i == f[i]){
            res = res + 1LL * q[i];
        }
    }
    printf("%lld\n",res);
    return 0;
}