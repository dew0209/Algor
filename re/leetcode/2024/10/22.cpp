//题目链接：https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-i/description/?envType=daily-question&envId=2024-10-22


/*
    暴力遍历
*/
class Solution {
public:
    int cnt[30];
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if((hours[i] + hours[j]) % 24 == 0){
                    res++;
                }
            }    
        }
        return res;
    }
};