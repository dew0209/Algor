/*
 * 约束之和
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010,MOD = 9901;

int n,m;

int qmi(int a,int b){
    a %= MOD;
    int res = 1;
    while (b){
        if(b & 1)res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}

int get(int u,int k){
    if(k == 0)return 1;
    if(k % 2 == 0)return (1 + u % MOD * get(u,k - 1) % MOD);
    return get(u,(k - 1) / 2) % MOD * (1 + qmi(u,(k + 1) / 2)) % MOD;
}

int main(){
    cin >> n >> m;
    int res = 1;
    for(int i = 2;i <= n;i++){
        int s = 0;
        while (n % i == 0){
            s++;
            n /= i;
        }
        if(s)res = res * get(i,s * m) % MOD;
    }
    if(!n)res = 0;
    cout << res << endl;

    return 0;
}

作者：一只可爱严
        链接：https://www.acwing.com/activity/content/code/content/1852527/
来源：AcWing
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。