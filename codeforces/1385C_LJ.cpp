//https://codeforces.com/problemset/problem/1385/C

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n;
int q[N];

//上升下降可以 单调也可以

void solve(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> q[i];
    int pos = n - 1;
    while(pos > 0 && q[pos - 1] >= q[pos])pos--;
    while(pos > 0 && q[pos - 1] <= q[pos])pos--;
    cout << pos << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}