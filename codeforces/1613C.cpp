#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N  = 100010;

LL q[N];

void solve(){
    LL n,m;cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> q[i];
    LL l = 1,r = 1e18;
    while(l < r){
        LL mid = (l + r) / 2;
        LL sum = mid;
        for(int i = 1;i < n;i++){
            sum += min(mid,q[i + 1] - q[i]);
        }
        if(sum >= m)r = mid;
        else l = mid + 1;
        //cout << l << "------" << r << endl;
    }
    cout << l << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}