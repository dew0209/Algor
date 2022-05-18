#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n,m;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> ans(n + 1);
    for(int i = 1;i <= m;i++){
        int a,b,c;cin >> a >> b >> c;
        ans[b] = 1;
    }
    int star = 1;
    while(ans[star])star++;
    for(int i = 1;i <= n;i++){
        if(i == star)continue;
        cout << i << ' ' << star << endl;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}