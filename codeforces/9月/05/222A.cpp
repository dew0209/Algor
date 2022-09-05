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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,k;
int q[N];

int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
    }
    bool ok = false;
    for(int i = k;i <= n;i++){
        if(q[i] != q[k]){
            ok = true;
        }
    }
    int idx = 0;

    for(int i = k - 1;i > 0;i--){
        if(q[i] != q[k]){
            idx = i;
            break;
        }
    }
    if(ok)cout << -1 << endl;
    else cout << idx << endl;

    return 0;
}