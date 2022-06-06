#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

void solve(){
    int n,m;cin >> n >> m;
    map<int,int> cnt;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        cnt[c % m]++;
    }
    int ans = 0;
    for(auto &c : cnt){
        if(c.first == 0)ans++;
        else if(2 * c.first == m){
            ans++;
        }else if(2 * c.first < m || cnt.find(m - c.first) == cnt.end()){
            int x = c.second,y = cnt[m - c.first];
            ans += 1 + max(0,abs(x - y) - 1);
        }
    }
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}