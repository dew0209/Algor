#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

void solve(){
    int a,b,n;
    cin >> a >> b;
    n = a + b;
    string s;cin >> s;
    for(int i = 0;i < n;i++)if(s[i] == '?')s[i] = s[n - 1 - i];
    a -= count(s.begin(),s.end(),'0');
    b -= count(s.begin(),s.end(),'1');
    for(int i = 0;i <= n / 2;i++){
        if(i != n - 1 - i && s[i] == '?'){
            if(a > 1)s[i] = s[n - i - 1] = '0',a -= 2;
            else if(b > 1)s[i] = s[n - i - 1] = '1',b -= 2;
        }else if(s[i] == '?'){
            if(a)s[i] = '0',a--;
            else if(b)s[i] = '1',b--;
        }
    }
    bool ok = true;
    for(int i = 0;i < n;i++){
        if(s[i] == '?')ok = false;
    }
    string v = s;
    reverse(v.begin(),v.end());
    if(v == s && a == 0 && b == 0 && ok)cout << s;
    else cout << -1;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}