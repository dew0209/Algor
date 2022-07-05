#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    vector<pair<int,int>> res;
    for(int i = 0;i < n;i++)cin >> a[i];
    int idx = -1;
    for(int i = 1;i < n;i++){
        if(a[i] != a[0]){
            idx = i;
            res.push_back({1,i + 1});
        }
    }
    if(idx == -1){
        cout << "NO" << endl;
    }else {
        for(int i = 1;i < n;i++){
            if(a[i] == a[0]){
                res.push_back({idx + 1,i + 1});
            }
        }
        cout << "YES" << endl;
        for(auto &c : res){
            cout << c.first << ' ' << c.second << endl;
        }
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}