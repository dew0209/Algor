题目链接：https://leetcode.cn/problems/next-greater-numerically-balanced-number/description/?envType=daily-question&envId=2023-12-09

class Solution {
public:
    bool check(int u){
        int tmp = u;
        vector<int> cnt(10,0);
        while(u){
            cnt[u % 10]++;
            u /= 10;
        }
        for(int i = 0;i <= 9;i++){
            if(cnt[i] != 0 && cnt[i] != i){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i = n + 1;i <= 1224444;i++){
            if(check(i)){
                return i;
            }
        }  
        return -1;
    }
};