// 题目链接：https://leetcode.cn/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2024-05-31

// 思路：暴力

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int  n = grid.size();
        int cnt[n * n + 10];
        memset(cnt,0,sizeof cnt);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cnt[grid[i][j]]++;
            }
        }
        int a = 0;
        int b = 0;
        for(int i = 1;i <= n * n;i++){
            if(cnt[i] == 0){
                a = i;
            }
            if(cnt[i] == 2){
                b = i;
            }
        }
        vector<int> res;
        res.push_back(b);
        res.push_back(a);
        return res;
    }
};