#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

void solve(){
    int n,a,b,c;
    // R         p           s
    cin >> n >> a >> b >> c;
    string s;cin >> s;
    string res = "";
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == 'R'){
            if(b){
                res += 'P';
                b--;
                ans++;
            }else {
                res += '-';
            }
        }
        if(s[i] == 'P'){
            if(c){
                res += 'S';
                c--;
                ans++;
            }else res += '-';
        }
        if(s[i] == 'S'){
            if(a){
                res += 'R';
                a--;
                ans++;
            }else res += '-';
        }
    }
    if(ans >= (n + 1) / 2){
        cout << "YES" << endl;
        for(int i = 0;i < n;i++){
            if(res[i] == '-'){
                if(a){
                    res[i] = 'R';
                    a--;
                }else if(b){
                    res[i] = 'P';
                    b--;
                }else if(c){
                    res[i] = 'S';
                    c--;
                }
            }
        }
        cout << res << endl;
    }else {
        cout << "NO" << endl;;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();
}