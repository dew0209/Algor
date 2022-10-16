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
int q[N];

int get2(int u){
    int cnt = 0;
    while(u % 2 == 0){
        cnt++;
        u /= 2;
    }
    return cnt;
}

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    int cnt = 0;
    vector<int> ans;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        if(q[i] % 2 == 0){
            //能够拆成几个2
            sum += get2(q[i]);
        }
        if(i % 2 == 0){
            //能够拆成几个2
            ans.push_back(get2(i));
        }
    }
    sort(ans.begin(),ans.end());
    if(sum >= n){
        cout << 0 << endl;
    }else {
        int res = 0;
        for(int i = ans.size() - 1;i >= 0;i--){
            sum += ans[i];
            res++;
            if(sum >= n)break;
        }
        if(sum >= n){
            cout << res << endl;
        }else {
            cout << -1 << endl;
        }
    }
    
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}