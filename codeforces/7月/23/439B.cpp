#include <iostream>
#include <algorithm>
#include <vector>

typedef long long LL;

using namespace std;

const int N = 100010;

int n,m;
int main(){
    cin >> n >> m;
    vector<LL> a(n);
    for(int i = 0;i < n;i++)cin >> a[i];
    sort(a.begin(),a.end());
    LL ans = 0;
    for(int i = 0;i < n;i++){
        LL tmp = m - i;
        tmp = max(tmp,1LL);
        ans += a[i] * 1LL * tmp;
    }
    cout << ans << endl;
}