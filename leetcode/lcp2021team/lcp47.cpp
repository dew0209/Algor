/*
 * 01背包
 * 队列不会影响顺序，只有栈会影响顺序，栈会把capacities[i] - 1 个人拦住
 * 为了让编号为k的人先进入，前k个人都要将其拦住，设置一些栈，使其大小为k
 * 设f[i]：表示背包体积恰好为i时的选择方案，这里也就是栈和的大小为i，其值为方案数
 * 对于当前安检点，如果capacities[i] - 1的大小没有超过k，我们便有机会将其设置为栈。
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 40010;

int f[N];
class Solution {
public:
    int securityCheck(vector<int>& capacities, int k) {
        memset(f,0,sizeof f);
        int n = capacities.size();
        f[0] = 1;
        for(int i = 0;i < n;i++){
            int v = capacities[i] - 1;
            //反向遍历是因为这是01背包
            for(int j = k;j >= v;j--){
                f[j] = (f[j] + f[j - v]) % 1000000007;
            }
        }
        return f[k];
    }
};