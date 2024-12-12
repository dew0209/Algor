//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int f[N][2];

void solve(){
    
    cin >> n;
    int v;
    for(int i = 1;i <= n;i++){
         cin >> v;
         f[i][0] = max(f[i - 1][0],f[i - 1][1]);
         f[i][1] = f[i - 1][0] + v;
    }
    cout << max(f[n][0],f[n][1]) << endl;
}

int main(){
    
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}