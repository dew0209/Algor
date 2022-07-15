#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n;
int q[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    for(int i = 1;i < n;i++){
        if(abs(q[i] - q[i + 1]) > 1){
            cout << "YES" << endl;
            cout << i << ' ' << i + 1;
            return;
        }
    }
    cout << "NO";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}