//dp


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n;
int g[N];
int f[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> g[i];
    }
    int res = 0;
    for(int i = 1;i <= n;i++){
        f[i] = 1;
        for(int j = 1;j < i;j++){
            if(g[j] > g[i]){
                f[i] = max(f[i],f[j] + 1);
            }
        }
        res = max(res,f[i]);
    }
    
    for(int i = n;i >= 1;i--){
        f[i] = 1;
        for(int j = n;j > i;j--){
            if(g[j] > g[i]){
                f[i] = max(f[i],f[j] + 1);
            }
        }
        res = max(res,f[i]);
    }
    cout << res << endl;
}

int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}