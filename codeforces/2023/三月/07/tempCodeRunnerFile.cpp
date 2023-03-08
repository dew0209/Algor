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

const int N = 100010;

LL n,m;

void solve(){
    scanf("%lld",&n);
    vector<PIL> cnt;
    for(int i = 2;i <= n / i;i++){
        int count = 0;
        while(n % 2 == 0){
            n /= 2;
            count++;
        }
        if(count > 0){
            cnt.pb({count,i});
        }
    }
    if(n > 1){
        cnt.pb({1,n});
    }
    sort(cnt.rbegin(),cnt.rend());
    vector<LL> ans(cnt[0].fi,cnt[0].se);
    for(int i = 1;i < cnt.size();i++){
        for(int j = 0;j < cnt[i].fi;j++){
            ans.back() = 1LL * cnt[i].se * ans.back();
        }
    }
    printf("%d\n",ans.size());
    for(int i = 0;i < ans.size();i++){
        printf("%lld ",ans[i]);
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}