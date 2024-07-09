//题目链接：https://leetcode.cn/problems/minimize-manhattan-distances/description/?envType=daily-question&envId=2024-07-09

//思路：数学

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> dx,dy;
        for(auto& p : points){
            dx.insert(p[0] + p[1]);
            dy.insert(p[0] - p[1]);
        }

        int res = 0x3f3f3f3f;

        for(auto& p : points){
            int x = p[0] + p[1];
            int y = p[0] - p[1];
            dx.erase(dx.find(x)); 
            dy.erase(dy.find(y)); 
            int ax = *dx.rbegin() - *dx.begin();
            int ay = *dy.rbegin() - *dy.begin();
            res = min(res,max(ax,ay));
            dx.insert(x);
            dy.insert(y);
        }
        return res;
    }
};