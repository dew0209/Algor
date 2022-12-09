#include <iostream>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 200010;
const int MOD = 1e9+7;

int q[N];

LL get_u(LL a,LL b,int p){
    LL res = 1;
    while(b){
        if(b & 1)res = (res * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    int n;cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
    }
    LL res = 0;
    sort(q + 1,q + n + 1);
    int st = n + 1;
    for(int i = 1;i <= n;i++){
        res = (res + q[i] * st % MOD) % MOD;
        st--;
    }
    LL d = get_u(4,n - 1,MOD);
    cout << res * d % MOD << endl;
    return 0;
}