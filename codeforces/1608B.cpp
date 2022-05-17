#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n,m;

void solve(){
    int a,b,c;cin >> a >> b >> c;
    if(abs(b - c) > 1 || b + c > a - 2)cout << -1 << endl;
    else {
        int l = 1,r = a;
        int ok = b > c;
        for(int i = 1;i <= a;i++){
            if(ok){
                cout << l++ << ' ';
            }else {
                cout << r-- << ' ';
            }
            if(i <= b + c)ok ^= 1;
        }
        cout << endl;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}