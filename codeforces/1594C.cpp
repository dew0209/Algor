#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long LL;
//i不能被x整除  i % x != 0
using namespace std;

void solve(){
    int n;cin >> n;
    char c;cin >> c;
    string s;cin >> s;
    vector<int> ans;
    int ok = 1;
    for(int i = 0;i < n;i++){
        if(s[i] != c){
            ok = 0;
        }
    }
    if(!ok){
        for(int i = 1;i <= n;i++){
            ok = 1;
            for(int j = i;j <= n;j += i){
                ok &= (s[j - 1] == c);
            }
            if(ok){
                ans.push_back(i);
                break;
            }
        }
        if(!ok){
            ans.push_back(n);
            ans.push_back(n - 1);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++)cout << ans[i] << ' ';
    cout << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}