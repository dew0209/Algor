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

const int N = 510;

using namespace std;

int n;
int q[N],p[N];

void solve(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)scanf("%d",&q[i]);
    for(int i = 1;i <= n;i++)scanf("%d",&p[i]);
    int ok1 = 0;
    int ok2 = 0;
    int ok3 = 1;
    for(int i = 1;i <= n;i++){
        if(p[i] == 0)ok1 = 1;
        if(p[i] == 1)ok2 = 1;
        if(i + 1 <= n && q[i] > q[i + 1])ok3 = 0;
    }
    if((ok1 && ok2) || ok3)printf("YES");
    else printf("NO");
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}