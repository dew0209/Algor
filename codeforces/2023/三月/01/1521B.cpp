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

const int N = 100010,MOD = 1e9 + 7;

int n;
int q[N];

//gcd(i,i+1) = 1

void solve(){
    scanf("%d",&n);
    int pos = -1;
    int x = MOD;
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
        if(q[i] < x)x = q[i],pos = i;
    }
    printf("%d\n",n - 1);
    for(int i = 0;i < n;i++){
        if(i == pos)continue;
        printf("%d %d %d %d\n",i + 1,pos + 1,x + abs(i - pos),x);
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}