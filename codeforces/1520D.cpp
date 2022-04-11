//https://codeforces.com/problemset/problem/1520/D
#include <iostream>
#include <cstring>
#include <map>

typedef long long LL;

using namespace std;

const int N = 200010;

int n;
map<int,int> mp;

void solve(){
    mp.clear();
    int n;cin >> n;
    for(int i = 1;i <= n;i++){
        int c;cin >> c;
        mp[c - i]++;
    }
    LL res = 0;
    for(auto &val : mp){
        if(val.second >= 2){
            res += ((LL)val.second * (val.second - 1)) / 2;
        }
    }
    cout << res << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}