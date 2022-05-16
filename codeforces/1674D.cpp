#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int q[N];
int n,m;

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
    }
    int st = 1;
    if(n % 2)st = 2;
    for(int i = st;i <= n;i += 2){
        if(q[i] > q[i + 1]){
            int temp = q[i];
            q[i] = q[i + 1];
            q[i + 1] = temp;
        }
    }
    bool ok = true;
    for(int i = 1;i < n;i++){
        if(q[i] > q[i + 1]){
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}