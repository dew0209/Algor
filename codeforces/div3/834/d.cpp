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

void solve(){
    LL n,m;cin >> n >> m;
    LL k = 1;
    LL n0 = n;
    LL cnt2 = 0,cnt5 = 0;
    while(n % 2 == 0){
        cnt2++;
        n /= 2;
    }
    while(n % 5 == 0){
        cnt5++;
        n /= 5;
    }
    //cout << cnt2 << "---" << cnt5 << endl;
    while(cnt2 < cnt5 && k * 2 <= m){
        cnt2++;
        k *= 2;
    }
    while(cnt5 < cnt2 && k * 5 <= m){
        cnt5++;
        k *= 5;
    }
    while(k * 10 < m){
        k *= 10;
    }
    if(k == 1){
        cout << n0 * m;
    }else {
        k *= m / k;
        cout << n0 * k;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}