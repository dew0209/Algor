#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 500010,MOD = 1e9 + 7;

int n,x,m;

void solve(){
    scanf("%d%d%d",&n,&x,&m);
    int l,r;
    int rl = x;
    int rr = x;
    while(m--){
        scanf("%d%d",&l,&r);
        //cout << l << ' ' << r << ' ' << rl << ' ' << rr << endl;
        if((rl >= l && rl <= r) || (rr >= l && rr <= r)){
            rl = min(l,rl);
            //cout << "ttt" << rl << endl;
            rr = max(r,rr);
        }
    }
    printf("%d",(rr - rl + 1));
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}