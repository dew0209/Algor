#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n,m;
long long q[N];

void solve(){
    cin >> n;
    int a = 0,b = 0;
    for(int i = 1;i <= n;i++)cin >> q[i];
    for(int i = 2;i < n;i++){
        if(q[i] != 1){
            a = 1;
        }
    }
    if(n == 3 && q[2] % 2 == 1)cout << "-1" << endl;
    else if(!a)cout << "-1" << endl;
    else {
        long long sum = 0;
        for(int i = 2;i < n;i++){
            sum += (q[i] + 1) / 2;
        }
        cout << sum << endl;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}