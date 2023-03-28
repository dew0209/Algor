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

const int N = 110;

void solve(){
    int n,m;scanf("%d%d",&n,&m);
    vector<int> a;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            a.pb(max(i - 1,n - i) + max(j - 1,m - j));
        }
    }
    sort(a.begin(),a.end());
    for(int re : a){
        printf("%d ",re);
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}