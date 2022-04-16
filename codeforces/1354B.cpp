//https://codeforces.com/problemset/problem/1354/B

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

void solve(){
    string s;cin >> s;
    int n = s.length();
    int q[n];
    char p[n];
    char c = s[0];
    int idx = 0;
    q[idx] = 1;
    p[idx] = c;
    for(int i = 1;i < n;i++){
        if(s[i] == c){
            q[idx]++;
        }else {
            q[++idx] = 1;
            c = s[i];
            p[idx] = c;
        }
    }
    int res = 1e9;
    for(int i = 1;i < idx;i++){
        if(p[i] != p[i - 1] && p[i + 1] != p[i] && p[i + 1] != p[i - 1]){
            res = min(res,q[i] + 2);
        }
    }
    if(res == 1e9)res = 0;
    cout << res << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}