#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int main(){
    int y,k,n;cin >> y >> k >> n;
    int step = k;
    while(step < y)step = step + k;
    int a0 = step - y;
    int cnt = (n - y - a0) / k;
    bool ok = true;
    for(int i = 0;i <= cnt;i++){
        if(a0 + i * k >= 1 && a0 + i * k + y <= n){
            cout << a0 + i * k << ' ';
            ok = false;
        }    
    }
    if(ok)cout << -1 << endl;
}