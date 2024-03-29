#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

void solve(){
    string s;cin >> s;
    int ans = 9;
    {
        int cnt0 = 0,cnt1 = 0;
        for(int i = 0;i < 10;i++){
            if(i % 2 == 0)cnt0 += s[i] != '0';
            else cnt1 += s[i] == '1';
            if(cnt0 > cnt1 + (10 - i) / 2)ans = min(ans,i);
            if(cnt1 > cnt0 + (9 - i) / 2)ans = min(ans,i);
        }
    }
    {
        int cnt0 = 0,cnt1 = 0;
        for(int i = 0;i < 10;i++){
            if(i % 2 == 0)cnt0 += s[i] == '1';
            else cnt1 += s[i] != '0';
            if(cnt0 > cnt1 + (10 - i) / 2)ans = min(ans,i);
            if(cnt1 > cnt0 + (9 - i) / 2)ans = min(ans,i);
        }
    }
    cout << ans + 1;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}