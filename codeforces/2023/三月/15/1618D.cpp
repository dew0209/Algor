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

const int N = 1010;

int n,m;
int q[N];

void solve(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    sort(q,q + n);
    int res = 0;
    for(int i = 0;i < n - 2 * m;i++){
        res += q[i];
    }
    for(int i = n - 2 * m;i < n - m;i++){
        if(q[i] == q[i + m])res++;
    }

    printf("%d",res);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}