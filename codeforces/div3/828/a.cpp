#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
int q[N];

void solve(){
    cin >> n;
    string s;
    for(int i = 1;i <= n;i++)cin >> q[i];
    vector<int> st(n + 1);
    cin >> s;
    if(n != s.size()){
        cout << "NO";
        return;
    }
    bool ok = true;
    for(int i = 1;i <= n;i++){
        //所有相同数字的位置是同一个字母即可
        char c = s[i - 1];
        int x = q[i];
        for(int j = 1;j <= n;j++){
            //cout << i << "--" << q[]
            if(q[j] == x){
                if(c != s[j - 1]){
                    ok = false;
                    break;
                }
            }
        }
    }
    if(ok)cout << "YES";
    else cout << "NO";
}

int main(){
    int T = 1;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}