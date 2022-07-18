#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long LL;

using namespace std;

const int N = 410;

int n,m;
int q[N];

void solve(){
    cin >> n;
    for(int i = 0;i < 4 * n;i++){
        cin >> q[i];
    }
    sort(q,q + 4 * n);
    bool ok = true;
    LL area = q[0] * q[4 * n - 1];
    for(int i = 0;i < n;i++){
        int l = i * 2,r = 4 * n - 1 - (2 * i);
        if(q[l] != q[l + 1] || q[r] != q[r - 1] || q[l] * 1LL * q[r] != area){
            ok = false;
            break;
        }
    }
    if(ok)cout << "YES";
    else cout << "NO";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}