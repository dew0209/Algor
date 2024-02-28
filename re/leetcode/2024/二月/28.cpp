题目链接：https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree/description/?envType=daily-question&envId=2024-02-28


思路：贪心

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
       int ans = 0;
       for(int i = n - 2;i >= 0;i -= 2){
           cost[i / 2] += max(cost[i],cost[i + 1]);
           ans += abs(cost[i] - cost[i + 1]);
       }
       return ans;
    }
};