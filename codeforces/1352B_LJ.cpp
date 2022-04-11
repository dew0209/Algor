//https://codeforces.com/problemset/problem/1352/B
#include <iostream>

using namespace std;

const int N = 110;

int n,m;

void solve(){
    cin >> n >> m;
    //1 ，，，，，， n1
    int n1 = n - (m - 1);
    if(n1 > 0 && (n1 % 2 == 1)){
        cout << "Yes" << endl;
        for(int i = 1;i <= m;i++){
            if(i != m)cout << 1 << ' ';
            else cout << n1 << endl;
        }
        return;
    }
    n1 = n - (m - 1) * 2;
    if(n1 > 0 && n1 % 2 == 0){
        cout << "Yes" << endl;
        for(int i = 1;i <= m;i++){
            if(i != m)cout << 2 << ' ';
            else cout << n1 << endl;
        }
        return;
    }
    cout << "No" << endl; 
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}