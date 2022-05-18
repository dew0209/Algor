#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200010;

int n;

void solve(){
    cin >> n;
    string s;cin >> s;
    int res = n + 1;
    for(int i = 0;i < 26;i++){
        int l = 0,r = n - 1;
        int cnt = 0;
        while(l <= r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else if(s[l] == char('a' + i)){
                l++;cnt++;
            }else if(s[r] == char('a' + i)){
                r--;cnt++;
            }else {
                cnt = n + 1;
                break;
            }
        }
        res = min(res,cnt);
    }
    if(res == n + 1)res = -1;
    cout << res << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}