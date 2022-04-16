//https://codeforces.com/problemset/problem/1339/B
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int q[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    int i = n / 2,j = n / 2 + 1;
    int t = 0;
    sort(q + 1,q + n + 1);
    while(i >= 1 || j <= n){
        if(t){
            cout << q[i] << ' ';
            i--;
            t = 0;
        }else {
            cout << q[j] << ' ';
            j++;
            t = 1;
        }
    }
    cout << endl;
}
int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}