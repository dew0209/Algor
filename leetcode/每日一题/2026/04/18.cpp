//https://leetcode.cn/problems/mirror-distance-of-an-integer/description/?envType=daily-question&envId=2026-04-18

class Solution {
public:
     int get_num(int u){
        if(u == 0)return 0;
        vector<int> num;
        while(u){
            num.push_back(u % 10);
            u /= 10;
        }
        reverse(num.begin(),num.end());
        //去掉0
        while(num.size() > 1 && num.back() == 0)num.pop_back();
        int res = 0;
        for(int i = num.size() - 1;i >= 0;i--){
            res = res * 10 + num[i];
        }
        return res;
    }
    int mirrorDistance(int n) {
        return abs(n - get_num(n));
    }
};