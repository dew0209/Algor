#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30;

int n,m;


void solve(){
    cin >> n;
    long long ans = 0;
    int cnt[30][30];
    memset(cnt,0,sizeof cnt);
    for(int i = 1;i <= n;i++){
        string s;cin >> s;
        for(int j = 0;j < 2;j++){
            for(char c = 'a';c <= 'k';c++){
                if(c == s[j])continue;
                string a = s;a[j] = c;
                ans += cnt[a[0] - 'a'][a[1] - 'a'];
            }
        }
        cnt[s[0] - 'a'][s[1] - 'a']++;
    }
    cout << ans << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}