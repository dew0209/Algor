#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 100010;

void solve(){
    int n,r;cin >> n >> r;
    LL res = 0;
    if(r >= n){
        r = n - 1;
        res = 1;
    } 
    res = res +  (1 + r) * 1LL * r * 1LL / 2;
    cout << res;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}