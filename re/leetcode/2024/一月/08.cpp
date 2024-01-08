题目链接：https://leetcode.cn/problems/number-of-boomerangs/description/?envType=daily-question&envId=2024-01-08

思路：哈希+枚举

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        for(auto& p : points){
            map<int,int> cnt;
            for(auto& q : points){
                int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                cnt[dis]++;
            }
            for(auto& [x,y] : cnt){
                res += y * (y - 1);
            }
        }
        return res;
    }
};