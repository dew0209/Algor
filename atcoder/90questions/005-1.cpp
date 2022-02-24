#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;

const int N = 10010,mod = 1e9 + 7;

int n,b,k;
int c[N];
//f[i][j]：i位整数 % b 的余数为j
LL f[64][N];


void init(){
    for(int i = 1;i <= k;i++){
        f[1][c[i] % b]++;
    }
}

//
void solve(){
    for(int i = 1;i < n;i++){
        for(int j = 0;j < b;j++){
            for(int t = 1;t <= k;t++){
                int nex = (10 * j + c[t]) % b;
                f[i + 1][nex] += f[i][j];
                f[i + 1][nex] %= mod;
            }
        }
    }
}

int main(){
    cin >> n >> b >> k;
    for(int i = 1;i <= k;i++)cin >> c[i];
    init();
    solve();
    cout << f[n][0] << endl;

    return 0;
}