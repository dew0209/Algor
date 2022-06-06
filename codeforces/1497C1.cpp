#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

void solve(){
    int n,k;cin >> n >> k;
    if(n % 2)cout << 1 << ' ' << n / 2 << ' ' << n / 2;
    else if(n % 2 == 0 && n % 4)cout << 2 << ' ' << n / 2 - 1 << ' ' << n / 2 - 1;
    else cout << n / 4 << ' ' << n / 4 << ' ' << n / 2;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}