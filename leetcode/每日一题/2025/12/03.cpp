//https://leetcode.cn/problems/count-number-of-trapezoids-ii/description/?envType=daily-question&envId=2025-12-03

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        //两两组合
        map<double,map<double,int>> cnt1;//斜率->截距->个数
        map<int,map<double,int>> cnt2;//中点->斜率->个数
        for(int i = 0;i < n;i++){
            int x1 = points[i][0],y1 = points[i][1];
            for(int j = i + 1;j < n;j++){
                int x2 = points[j][0],y2 = points[j][1];
                int dx = x2 - x1;
                int dy = y2 - y1;
                double k = dx ? 1.0 * dy / dx : DBL_MAX;
                double b = dx ? 1.0 * (y1 * dx - x1 * dy) / dx : x1;
                cnt1[k][b]++;
                double mid = (x1 + x2 + 2000) << 16 | (y1 + y2 + 2000);
                cnt2[mid][k]++;
            }
        }
        int ans = 0;
        for(auto& [xxx,m] : cnt1){
            int s = 0;
            for(auto& [yyyy,c] : m){
                ans += s * c;
                s += c;
            }
        }

        for(auto& [_,m] : cnt2){
            int s = 0;
            for(auto& [_,c] : m){
                ans -= s * c;
                s += c;
            }
        }
        return ans;
    }
};