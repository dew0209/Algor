#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200010;

LL n,m;
LL q[N];

LL query(int l,int r){
    return q[r] - (l ? q[l - 1] : 0);
}

void solve(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> q[i];
        if(i)q[i] += q[i - 1];
    }
    LL ans = INT_MAX;
    for(int i = 0;i < n;i++){
        int l = i,r = n - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(query(i,mid) <= m){
                l = mid;
            }
            else r = mid - 1;
        }
        if(query(i,l) != m)continue;
        ans = min(ans,n - (l - i + 1));
    }
    if(ans == INT_MAX)ans = -1;
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}