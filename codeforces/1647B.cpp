#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int n,m;
int g[110][110];

void solve(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        string s;cin >> s;
        for(int j = 0;j < m;j++){
            g[i][j] = s[j] - '0';
        }
    }
    bool ok = false;
    for(int i = 0;i < n - 1;i++){
        if(ok)break;
        for(int j = 0;j < m - 1;j++){
            int sum = g[i][j] + g[i + 1][j] + g[i][j + 1] + g[i + 1][j + 1];
            if(sum == 3)ok = true;
        }
    }
    if(ok)cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}