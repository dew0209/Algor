#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 210,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
int q[N];
int st[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= 2 * n;i++){
        st[i] = false;
    }
    for(int i = 1;i <= n;i++){
        int c;cin >> c;
        q[2 * i - 1] = c;
        st[c] = true;
    }
    bool ok = false;
    for(int i = 1;i <= n;i++){
        int c = q[2 * i - 1] + 1;
        while(st[c] && c <= 2*n)c++;
        if(c > 2 * n){
            ok = true;
            break;
        }
        st[c] = true;
        q[2 * i] = c;
    }
    if(ok){
        cout << "-1";
    }else {
        for(int i = 1;i <= 2*n;i++){
            cout << q[i] << ' ' ;
        }
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}