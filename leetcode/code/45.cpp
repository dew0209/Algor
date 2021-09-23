/*
 * 45. 跳跃游戏 II [https://leetcode-cn.com/problems/jump-game-ii/]
 * 现在，我们在i的位置上，我们该如何选择一个i能够到的地方，使得答案最优呢?
 * 选择i + nums[i] 中最大的吗? --> 不对，最大的不一定跳最远，设选择的点为k,选择之后 k + nums[k],但是k 和 i + nums[i]之间还是存在距离的，有可能存在点 t （k < t <= i + nums[i]）,使得 t + nums[t] > k + nums[k]
 * 所以，我们应该选择一个相对与i + nums[i] 最远的点，这样我们的答案是最优的，并且在选择了该点之后，下一次能够选择的点也更多。
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

/*
    class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        int maxv = 0;
        int ans = 0;
        for(int i = 0;i < n - 1;i++){
            maxv = max(maxv,i + nums[i]);
            if(len == i){
                len = maxv;
                ans++;
            }
        }
        return ans;
    }
};
 */


/*
 * 我写的，和官方的贪心题解不同的是，更加容易理解一些
 *      一上来能够到达的位置是nums[0]
 *      在枚举完 len 之后 我们才进行更新操作，而官方需要在刚好在len时进行更新
 *      最后需要++ans，因为最后一跳没有包含在内
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        int len = nums[0];
        int maxv = 0;
        int ans = 0;
        for(int i = 1;i < n;i++){
            if(len >= i){
                maxv = max(maxv,i + nums[i]);
            }else {
                len = maxv;
                maxv = max(maxv,i + nums[i]);
                ans++;
            }
        }
        return ++ans;
    }
};