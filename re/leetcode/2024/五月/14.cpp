// 题目链接：https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/?envType=daily-question&envId=2024-05-14

// 思路：模拟

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> cnt;
        int n = tasks.size();   
        for(int i = 0;i < n;i++){
            cnt[tasks[i]]++;
        }   
        int res = 0;  
        for(auto [x,y] : cnt){
            if(y < 2)return -1;
            res += (y + 2) / 3;
        }
        return res;
    }
};