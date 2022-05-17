#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int n,m;
long long q[200010];


void solve(){
    cin >> n >> m;
    map<long long,int> mp;
    for(int i = 0;i < n;i++){
        cin >> q[i];
        mp[q[i]]++;
    }
    int ans = 0;
    sort(q,q + n);
    for(int i = 0;i < n;i++){
        long long newX = q[i] * m;
        if(mp[q[i]] == 0)continue;
        if(mp[newX]){
            mp[newX]--;  
        }else if(mp[q[i]]) {
            ans++;
        }
        mp[q[i]]--;
    }
    cout << ans << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}