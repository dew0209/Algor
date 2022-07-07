#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;



void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> c(n + 1);
    //memset(a,0,sizeof a);
    //memset(c,0,sizeof c);
    //memset(b,0,sizeof b);
    for(int i = 1;i <= n;i++){
        int m;cin >> m;
        for(int j = 1;j <= m;j++){
            cin >> c[j];
        }
        for(int j = 1;j <= m;j++){
            if(!b[c[j]]){
                a[i] = 1;
                b[c[j]] = 1;
                break;
            }
        }
    }
    bool ok = false;
    for(int i = 1;i <= n;i++){
        if(!a[i]){
            cout << "IMPROVE" << endl;
            for(int j = 1;j <= n;j++){
                if(!b[j]){
                    cout << i << ' ' << j << endl;
                    ok = true;
                    return;
                }
            }
        }
    }
    if(!ok)cout << "OPTIMAL" << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}