//题目链接：https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-ii/description/?envType=daily-question&envId=2024-10-23


/*
    哈希表
*/

class Solution {
public:
    int cnt[30];
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();

        long long res = 0;

        for(int i = 0;i < n;i++){
            
            int x = hours[i] % 24;

            res = res + cnt[(24 - x) % 24];

            cnt[x]++;

        }
        return res;

    }
};