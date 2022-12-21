#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 20;

int d[10][10];

int main(){
    for(int i = 1;i <= 4;i++){
        for(int j = 0;j < 4;j++){
            cin >> d[i][j];
        }
    }
    for(int i = 0;i < 4;i++){
        d[0][i] = d[4][i];//copy
        d[5][i] = d[1][i];
        d[6][i] = d[2][i];
    }
    bool ok = 0;
    for(int i = 1;i <= 4;i++){
        if(d[i][3] == 1 && (d[i - 1][2] == 1 || d[i + 1][0] == 1 || d[i + 2][1] == 1 || d[i][0] == 1 || d[i][1] == 1 || d[i][2] == 1)){
            ok = 1;
            break;
        }
    }
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}