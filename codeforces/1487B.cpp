#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

void solve(){
    int n,k;cin >> n >> k;
    int floor = n / 2;
    k--;
    cout << (k + (n % 2) * (k / floor)) % n + 1;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}