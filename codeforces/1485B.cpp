#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int main(){
    int n,q,m;cin >> n >> q >> m;
    vector<int> a(n + 2);
    for(int i = 1;i <= n;i++)cin >> a[i];
    while(q--){
        int l,r;cin >> l >> r;
        int ans = 0;
        ans += a[l] - 1;
        ans += m - a[r];
        ans += (a[r] - a[l] + 1) - (r - l + 1);
        ans += (a[r] - a[l] + 1) - (r - l + 1);
        cout << ans << endl;
    }
}
