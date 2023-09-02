题目链接：https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/description/?envType=daily-question&envId=2023-09-02

方法一：模拟

class Solution {
public:
    int captureForts(vector<int>& forts) {
         int res = 0,pre = -1;
         for(int i = 0;i < forts.size();i++){
             if(forts[i] == 1 || forts[i] == -1){
                 if(pre >= 0 && forts[i] != forts[pre]){
                     res = max(res,i - pre - 1);
                 }
                 pre = i;
             }
         }
         return res;
    }
};