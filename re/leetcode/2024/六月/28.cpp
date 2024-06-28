//题目连接：https://leetcode.cn/problems/painting-the-walls/description/?envType=daily-question&envId=2024-06-28

//思路：dp

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> f(n + 10,0x3f3f3f3f / 2);
        f[0] = 0;
        for(int i = 0;i < n;i++){
            int c = cost[i],t = time[i] + 1;
            for(int j = n;j;j--){
                f[j] = min(f[j],f[max(j - t,0)] + c);
            }
        }
        return f[n];
    }
};