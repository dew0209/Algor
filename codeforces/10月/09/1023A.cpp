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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m;
string s,t;

int main(){
    cin >> n >> m;
    cin >> s >> t;
    bool ok = false;
    int idx = -1;
    for(int i = 0;i < n;i++){
        if(s[i] == '*'){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout << (s == t ? "YES" : "NO") << endl;
        return 0;
    }
    //检查
    for(int i = 0;i < idx;i++){
        if(i >= m || s[i] != t[i]){
            ok = true;
            //cout << "debug1 " << i << endl;
            break;
        }
    }
    int j = m - 1;
    for(int i = n - 1;i > idx;i--,j--){
        if(j < 0 || s[i] != t[j]){
            ok = true;
            //cout << "debug1 " << i << endl;
            break;
        }
    }
    if(ok || n - 1 > m)cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}