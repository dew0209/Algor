//https://leetcode.cn/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2026-01-12


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for(int i = 1;i < n;i++){
            int a = points[i][0];
            int b = points[i][1];

            int x = points[i - 1][0];
            int y = points[i - 1][1];
            int dx = abs(a - x);
            int dy = abs(b - y);

            res += min(dx,dy) + abs(dx - dy);

        }
        return res;
    }
};