#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

typedef long long LL;

using namespace std;

const int N  = 100010;

int n;

void solve(){
    //k (n - 2) = s(n - 2) / n = (ns - 2s) / n = s - 2s / n
    cin >> n;
    vector<int> q(n);
    map<int,int> mp;
    LL sum = 0;
    for(int i = 0;i < n;i++){
        cin >> q[i];
        sum += q[i];
        
    }
    if((2 * sum) % n != 0){
        cout << 0 << endl;
    }else {
        LL ans = (2 * sum) / n;
        LL res = 0;
        for(int i = 0;i < n;i++){
            res += mp[ans - q[i]];
            mp[q[i]]++;
        }
        cout << res << endl;
    }

}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}