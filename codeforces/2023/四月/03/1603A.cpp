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

int n,m;
int q[N];

void solve(){
    int ok = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
    }
    for(int i = 1;i <= n;i++){
        int fl = 0;
        for(int j = 1;j <= i;j++){
            if(q[i] % (j + 1)){
                fl = 1;
                break;
            }
        }
        ok = fl;
        if(!ok)break;
    }
    if(ok)printf("Yes");
    else printf("No");
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}