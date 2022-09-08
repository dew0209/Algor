#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
int q[N],p[N];

int main(){
    cin >> n;
    string s;cin >> s;
    bool ok = true;
    for(int i = 0;i < n - 1;i++){
        if(s[i] == '1' && s[i + 1] == '1'){
            ok = false;
        }
    }
    s += "0";
    s = "0" + s;
    for(int i = 0;i < n - 1;i++){
        if(s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0'){
            ok = false;
        }
    }
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}