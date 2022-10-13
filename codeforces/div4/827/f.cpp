#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;

void solve(){
    cin >> n;
    vector<int> cnt1(26,0);
    vector<int> cnt2(26,0);
    cnt1[0] = cnt2[0] = 1;
    for(int i = 0;i < n;i++){
        int a,b;
        string c;
        cin >> a >> b >> c;
        if(a == 1){
            for(int j = 0;j < c.size();j++){
                cnt1[c[j] - 'a'] += b;
            }
        }else {
            for(int j = 0;j < c.size();j++){
                cnt2[c[j] - 'a'] += b;
            }
        }
        bool ok = false;
        int idx1 = -1;
        int idx2 = -1;
        for(int j = 25;j >= 0;j--){
            if(cnt1[j] != 0 && idx1 == -1){
                idx1 = j;
            }
        }
        for(int j = 25;j >= 0;j--){
            //cout << cnt2[j] << "ddd";
            if(cnt2[j] != 0 && idx2 == -1){
                idx2 = j;
            }
        }
        //cout << endl;
        //cout << idx1 << "debug" << idx2 << endl;
        if(idx2 > 0)ok = true;
        if(idx1 == idx2 && idx2 == 0 && cnt1[0] < cnt2[0])ok = true;
        if(ok)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}