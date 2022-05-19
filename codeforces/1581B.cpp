#include <iostream>
#include <cstring>

typedef long long LL;

using namespace std;

const int N = 100010;

void solve(){
    int a,b,c;cin >> a >> b >> c;
    LL sum = 1LL * a * (a - 1) / 2;
    int len = 2;
    if(sum <= b)len = 1;
    if(a == 1)len = 0,sum = 0;
    if(b < a - 1 || sum < b)cout << "NO" << endl;
    else if(len < c - 1)cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}