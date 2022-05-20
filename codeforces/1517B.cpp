#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int q[110][110];

void solve(){
    cin >> n >> m;
    int sum = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)cin >> q[i][j];
    int st = 1;
    for(int i = 1;i <= n;i++){
        sort(q[i] + 1,q[i] + 1 + m);
    }
    for(int j = m;j >= 1;j--){
        int p = 1;
        for(int i = 1;i <= n;i++){
            if(q[i][1] < q[p][1]){
                p = i;
            }
        }
        rotate(q[p] + 1,q[p] + 2,q[p] + j + 1);
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cout << q[i][j] << ' '; 
        }
        cout << endl;
    }
    
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}