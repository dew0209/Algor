//题目链接：https://leetcode.cn/problems/minimum-levels-to-gain-more-points/?envType=daily-question&envId=2024-07-19

//思路：前缀和

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> cnt(n + 10,0);
        for(int i = 1;i <= n;i++){
            cnt[i] = possible[i - 1] == 0 ? -1 : 1;
            cnt[i] += cnt[i - 1];
        }
        for(int i = 1;i < n;i++){
            int a = cnt[i];
            int b = cnt[n] - cnt[i];
            if(a > b)return i;
        }
        return -1;
    }
};