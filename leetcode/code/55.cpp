/*
 * 55. 跳跃游戏 [https://leetcode-cn.com/problems/jump-game/]
 * f[i]：表示从1~i中，选择点进行跳跃能够到达的最远位置，状态表示为这个比较好，如果定义为f[i]为点i能够达到的最远的点，有点勉强
 * f[i] = max(f[i - 1],i + nums[i])：注意，必须要和f[i - 1]作比较，因为能够达到最远的点，不一定是i + nums[i],存在 t < i -> t + nums[t] > i + nums[i]
 * 设f[i] = len，那么 1 ~ len都是可以到达的.
 */
/*
    int f[30010];
    class Solution {
    public:
        bool canJump(vector<int>& nums) {
            memset(f,0,sizeof f);
            int n = nums.size();
            if(n == 1)return 1;
            f[0] = nums[0];
            for(int i = 1;i < n;i++){
                if(f[i - 1] >= i){
                    f[i] = max(f[i - 1],i + nums[i]);
                }
                if(f[i] >= n - 1)return true;
            }
            return false;
        }
    };
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
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for(int i = 0;i < n;i++){
            if(i <= len){//可以跳到才更新，跳不到后面一直不会被更新 因为 i  > len 那么 i + 1 > len
                len = max(len,i + nums[i]);
            }
            if(len >= n - 1)return true;
        }
        return false;
    }
};

