// 题目链接：https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/description/?envType=daily-question&envId=2024-05-11

// 思路：暴力

class Solution {
public:

    int get(string s,char c){
        int res = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == c){
                res++;
            }
        }
        return res;
    }

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int a = 0;
        int b = 0;
        int c = 0;
        int ta = 0;
        int tb = 0;
        int tc = 0;
        int n = garbage.size();
        for(int i = 0;i < n;i++){
            int t = 0;
            t = get(garbage[i],'M');
            if(t != 0){
                a = a + ta + t;
                if(i < n - 1){
                    ta = 0;
                }
            }
            t = get(garbage[i],'P');
            if(t != 0){
                b = b + tb + t;
                tb = 0;
            }
            t = get(garbage[i],'G');
            if(t != 0){
                c = c + tc + t;
                tc = 0;
            }
            if(i < n - 1){
                ta += travel[i];
                tb += travel[i];
                tc += travel[i];
            }

        }
        return a + b + c;
    }
};