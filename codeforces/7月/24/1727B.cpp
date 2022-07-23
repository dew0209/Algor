#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N = 100010;

int n;
string s = "LRUD";

void solve(){
    map<char,int> cnt;
    string s1;cin >> s1;
    for(auto c : s)cnt[c] = 0;
    for(auto c : s1)cnt[c]++;
    int w = min(cnt['L'],cnt['R']);
    int h = min(cnt['U'],cnt['D']);
    if(!w || !h){
        if(!w){
            h = min(h,1);
            cout << 2 * h << endl << string(h,'U') + string(h,'D') <<endl;
        }else {
            w = min(w,1);
            cout << 2 * w << endl << string(w,'L') + string(w,'R') <<endl;
        }
    }else {
        string res;
        res += string(w,'L');
        res += string(h,'U');
        res += string(w,'R');
        res += string(h,'D');
        cout << res.size() << endl << res << endl;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}