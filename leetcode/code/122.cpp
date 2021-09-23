/*
 *  122. 买卖股票的最佳时机 II [https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/]
 *  dp：
 *      状态机做法：当前点的状态有两种，一种是持有股票，一种是不持有股票
 *                不持有股票的上一轮，可以持有可以不持有
 *                持有股票的上一轮，可以持有可以不持有
 *                为什么符合多次交易这个条件呢
 *                模拟样例：
 *                  [7,1,5,3,6,4]
 *                计算的dp数组结果为：0 -> 不持有股票 1 -> 持有股票
 *                  0  1   价格
 *
 *                  0 -7    7
 *                  0 -1    1  买入
 *                  4 -1    5  卖出
 *                  4 1     3  买入
 *                  7 1     6  卖出  -->  7
 *                  7 3     4
 *                  是可以满足多笔交易，且不会同时参与多笔交易的
 *   贪心：
 *       原题 --> 找到几个不相交的区间，使得每个区间的左右端点差值之和最大
 *               a[l] - a[r] = a[r + 1] - a[r] + a[r + 2] - a[r + 1] + ... + a[l] - a[l - 1];
 *               所以原题可以简化为：a[i] - a[i - 1]的和，但是这里要主意：a[i] - a[i - 1] > 0才可以
 *               所以：就是把所有上升的相邻位置加起来即可
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <deque>
#include <queue>
#include <set>

using namespace std;

#define fi first
#define se second

typedef long long LL;
typedef pair<int,int> PII;

const int N = 110;

int n,m;
int g[N][N];
int f[N][N];
PII path[N][N];


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f[30010][2];
        f[0][1] = -prices[0];
        f[0][0] = 0;
        for(int i = 1;i < n;i++){
            f[i][0] = max(f[i - 1][0],f[i - 1][1] + prices[i]);
            f[i][1] = max(f[i - 1][1],f[i - 1][0] - prices[i]);
        }
        return f[n - 1][0];
    }
};
/*
 * 贪心解法
 *
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        for(int i = 1;i < n;i++){
            res +=  max(0,prices[i] - prices[i - 1]);
        }
        return res;
    }
};
 */
