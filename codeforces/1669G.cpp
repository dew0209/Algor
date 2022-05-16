#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char g[110][110];

int n,m;

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> g[i][j];
    for(int i = m;i >= 1;i--){
        int st = n;
        for(int j = n;j >= 1;j--){
            if(g[j][i] == 'o')st = j - 1;
            else if(g[j][i] == '*' && st >= j){
                g[st][i] = '*';
                if(st > j)g[j][i] = '.';
                st--;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cout << g[i][j];
        }
        cout << endl;
    }
    
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}