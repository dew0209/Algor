/*
 * 股票买卖
 * 设f[i][k][0/1]：设从[1,i]中选择，当前正在进行第k笔交易，0代表不选当前，1代表选择当前
 * 设持有一次股票为一次新的交易
 *
 * 以for(int j = 1;j <= m;j++)的遍历进行模拟  初始化f[0-n][0][0] = 0
 * 模拟案例：
 *  6 2
 *  3 2 6 5 0 3
 *
 *  数组f
 *      i j    不持有     持有
 *      1 1 -1044266556 -3                   3           持有会更大，虽然为负数 -3
 *      1 2 -1044266556 -1044266559                      进行两笔交易：需要用到子状态：f[i - 1][j/j-1][0/1]
 *      debug
 *      2 1 -1          -2                   2           max(-3,f[2,0,0] - 2)  由此可以看出f[i][0][0]是可能被用到的：第i天，进行了0笔交易，不持有股票的利润是0，这是符合f的状态定义的
 *      2 2 -1044266556 -1044266558
 *      debug
 *      3 1   4         -2                   6
 *      3 2 -1044266552 -7
 *      debug
 *      4 1   4         -2                   5
 *      4 2  -2         -1
 *      debug
 *      5 1   4          0                   0
 *      5 2  -1          4
 *      debug
 *      6 1   4          0                   3
 *      6 2   7          4
 *      debug
 *      有些状态我们是不会被用到的，例如：f[i][j > i][0/1]：因为交易的笔数是超过了所有的股票数
 *      优化循环为：for(int j = 1;j <= min(i,m);j++)
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010,M = 110;

int n,m;
int f[N][M][2];

int main(){
    cin >> n >> m;
    int c;
    memset(f,-0x3f,sizeof f);
    for(int i = 0;i <= n;i++)f[i][0][0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> c;
        for(int j = 1;j <= m;j++){
            //no
            f[i][j][0] = max(f[i - 1][j][0],f[i - 1][j][1] + c);
            //yes
            f[i][j][1] = max(f[i - 1][j][1],f[i - 1][j - 1][0] - c);//f[i - 1][j - 1][0]延续过来 在有值的情况下，f[i][j][0] >= f[i - 1][j][0]
        }
    }
    int res = 0;
    //question:为什么最后计算结果的时候，不用将f[n][i][1]考虑在内？why  f[i - 1][j - 1][0]会被延续过来
    for(int i = 1;i <= m;i++)res = max(f[n][i][0],res);
    cout << res << endl;

    return 0;
}