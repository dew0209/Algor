/*
 * 跑两次dp解决方格取数问题
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
        return prices[n - 1][0];
    }
};