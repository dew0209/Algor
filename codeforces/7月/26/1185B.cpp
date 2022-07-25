#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define fi first
#define se second

using namespace std;

const int N = 100010;

vector<pair<char,int>> split(string s){
    vector<pair<char,int>> res;
    char c = s[0];
    int cnt = 1;
    for(int i = 1;i <= s.size();i++){
        if(s[i] != c){
            res.push_back({c,cnt});
            c = s[i];
            cnt = 1;
        }else cnt++;
    }
    return res;
}

void solve(){
    string a,b;cin >> a >> b;
    vector<pair<char,int>> cnta;
    vector<pair<char,int>> cntb;
    cnta = split(a);
    cntb = split(b);
    bool ok = cnta.size() == cntb.size();
    if(ok){
        for(int i = 0;i < cnta.size();i++){
            if(cnta[i].fi != cntb[i].fi || cnta[i].se > cntb[i].se){
                ok = false;
                break;
            }
        }
    }
    if(ok)cout << "YES";
    else cout << "NO";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}