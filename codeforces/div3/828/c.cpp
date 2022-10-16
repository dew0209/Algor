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

int n,q;

void solve(){
    cin >> n;
    char c;cin >> c;
    string s;cin >> s;
    s = s + s;
    n = s.size();
    int a = -1,b = -1;
    int ma = 0,mb = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == 'r' && a == -1){
            //cout << "way1 ";
            a = i;
        }
        if(s[i] == 'y' && b == -1){
            //cout << "way2 ";
            b = i;
        }
        if(s[i] == 'g'){
            //cout << "way3 ";
            if(a != -1){
                ma = max(i - a,ma);
                a = -1;
            }
            if(b != -1){
                mb = max(i - b,mb);
                b = -1;
            }
        }
    }
    if(c == 'r')cout << ma << endl;
    else if(c == 'y')cout << mb << endl;
    else cout << 0 << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}