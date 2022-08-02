#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7;

int n,k;
int a[N],b[N];

int main(){
    cin >> n >> k;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n;i++)cin >> b[i];
    vector<int> cnt;
    LL res = 0;
    for(int i = 0;i < n;i++){
        cnt.push_back(a[i] - b[i]);
        res += b[i];
    }
    sort(cnt.begin(),cnt.end());
    for(int i = 0;i < k || (cnt[i] <= 0 && i < cnt.size());i++){
        res += cnt[i];
    }
    cout << res << endl;
}