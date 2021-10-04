/*
 * 1058 股票买卖
 * 设f[i][0/1/2]：[1,i]中进行选择，0代表持有股票,1代表不持有股票第一天，2代表不持有股票>=2天
 *
 * 三个状态的状态机
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int f[N][3];

int main(){
    //0持有股票 1不持有股票第一天 2不持有股票第二天
    cin >> n;
    memset(f,-0x3f,sizeof f);
    f[0][2] = 0;
    int c;
    for(int i = 1;i <= n;i++){
        cin >> c;
        f[i][0] = max(f[i - 1][0],f[i - 1][2] - c);
        f[i][1] = f[i - 1][0] + c;
        f[i][2] = max(f[i - 1][1],f[i - 1][2]);
    }
    cout << max(f[n][1],f[n][2]) << endl;

    return 0;
}