#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    bool ok1 = false;
    bool ok2 = false;
    for(int i = 0;i < n;i++){
        if(s[i] == '<')ok1 = true;
        if(s[i] == '>')ok2 = true;
    }
    if(ok1 && ok2){
        s += s[0];
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '-' || s[i + 1] == '-')ans++;
        }
        cout << ans;
    }else cout << n;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}