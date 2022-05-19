#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int n,m;
int q[N];

void solve(){
    cin >>  n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    if(q[1]){
        cout << n + 1 << ' ';
        for(int i = 1;i <= n;i++)cout << i << ' ';
    }else {
        for(int i = 1;i < n;i++){
            if(!q[i] && q[i + 1]){
                for(int j = 1;j <= i;j++){
                    cout << j << ' ';
                }
                cout << n + 1 << ' ';
                for(int j = i + 1;j <= n;j++){
                    cout << j << ' ';
                }
                return;
            }
        }
        for(int i = 1;i <= n + 1;i++){
            cout << i << ' ';
        }
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}