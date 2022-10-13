#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 1000010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
string q[8];

void solve(){
    for(int i = 0;i < 8;i++){
            cin >> q[i];
    }
    //
    //cout << "?" << endl;
    for(int i = 0;i < 8;i++){
        char c = q[i][0];
        bool ok = true;
        for(int j = 0;j < 8;j++){
            if(c != q[i][j] || c == '.'){
                ok = false;
                break; 
            }
        }
        if(ok && c == 'R'){
            cout << "R";
            return;
        }
    }
    for(int i = 0;i < 8;i++){
        char c = q[0][i];
        bool ok = true;
        for(int j = 0;j < 8;j++){
            if(c != q[j][i] || c == '.'){
                ok = false;
                break;
            }
        }
        if(ok && c == 'B'){
            cout << "B";
            return;
        }
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}