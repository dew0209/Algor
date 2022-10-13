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

int n,m;
LL q[N];

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
    }
    vector<LL> res(m + 100);
    vector<pair<LL,LL>> query;
    for(int i = 1;i <= m;i++){
        int c;cin >> c;
        query.push_back({c,i});
    }
    sort(query.begin(),query.end());
    LL sum = 0;
    int idx = 0;
    int i = 1;
    //cout << "dede" << endl;
    while(idx < m){
        while(i <= n && q[i] <= query[idx].fi){
            sum += q[i++];
        }
        //cout << idx << "budeg" << endl;
        res[query[idx].se] = sum;
        idx++;
    }
    for(int j = 1;j <= m;j++){
        cout << res[j] << ' ';
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}