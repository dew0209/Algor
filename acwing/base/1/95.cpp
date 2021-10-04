/*
 * 费解的开关
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;

char g[N][N],bg[N][N];

int dx[5] = {-1,0,1,0,0},dy[5] = {0,1,0,-1,0};

void turn(int x,int y){
    for(int i = 0;i < 5;i++){
        int a = dx[i] + x,b = dy[i] + y;
        if(a < 0 || a >= 5 || b < 0 || b >= 5)continue;
        bg[a][b] ^= 1;
    }
}

void solve(){
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++)cin >> g[i][j];
    int res = 10;
    //枚举第一行按开关的位置
    for(int i = 0;i < 1<<5;i++){
        int cnt = 0;
        memcpy(bg,g,sizeof g);
        //处理第一行
        for(int j = 0;j < 5;j++){
            if((i >> j) & 1){
                turn(0,j);
                cnt++;
            }
        }
        //枚举其他行
        for(int j = 0;j < 4;j++){
            for(int k = 0;k < 5;k++){
                if(bg[j][k] == '0'){
                    turn(j + 1,k);
                    cnt++;
                }
            }
        }
        //看最后一行是否满足要求
        bool ok = true;
        for(int j = 0;j < 5;j++){
            if(bg[4][j] == '0')ok = false;
        }
        if(ok && cnt < res)res = cnt;
    }
    if(res > 6)res = -1;
    cout << res << endl;
}

int main(){
    int T = 1;cin >> T;
    while (T--)solve();

    return 0;
}