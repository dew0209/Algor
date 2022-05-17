#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int q[2000010];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
    }
    if(q[n] < 0 && is_sorted(q + 1,q + n + 1))cout << 0 << endl;
    else if(q[n] < 0)cout << "-1" << endl;
    else if(q[n - 1] > q[n])cout << "-1" << endl;
    else {
        cout << n - 2 << endl;
        for(int i = 1;i <= n - 2;i++){
            cout << i << ' ' << n - 1 << ' ' << n << endl;
        }
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}