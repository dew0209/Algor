//https://codeforces.com/contest/1294/problem/B
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;

int n,m;

void solve(){
    cin >> n;
    vector<pair<int,int>> a;
    for(int i = 0;i < n;i++){
        int x,y;cin >> x >> y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end());
    pair<int,int> cur = make_pair(0,0);
    string ans = "";
    bool ok = true;
    for(int i = 0;i < n;i++){
        int r = a[i].first - cur.first;
        int u = a[i].second - cur.second;
        if(r < 0 || u < 0){
            ok = false;
            break;
        }
        ans += string(r,'R');
        ans += string(u,'U');
        cur = a[i];
    }
    if(ok){
        cout << "YES" << endl;cout << ans;
    }
    else cout << "NO";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}