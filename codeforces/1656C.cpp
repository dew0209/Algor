#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n;
int q[N];


void solve(){
    cin >> n;
    int a = 0,b = 0,c = 0;
    for(int i = 0;i < n;i++)
        cin >> q[i];
    sort(q,q + n);
    for(int i = 0;i < n;i++){
        if(q[i] == 1)a = 1;
        if(i < n - 1 && q[i] + 1 == q[i + 1])b = 1;
    }
    if(a && b)cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}