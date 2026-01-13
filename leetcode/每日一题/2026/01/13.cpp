//https://leetcode.cn/problems/separate-squares-i/?envType=daily-question&envId=2026-01-13


class Solution {
public:
    bool cmp(double up,double down){
        if(fabs(up - down) < 1e-5){
            return false;
        }
        return down <= up;
    }
    bool check(vector<vector<int>>& squares,int n,double u){
        double down = 0;
        double up = 0;

        for(int i = 0;i < n;i++){
            int x = squares[i][0];
            int y = squares[i][1];
            int r = squares[i][2];
            if(y + r <= u){
                down = down + (1LL * r * r);
            }else if(y >= u){
                up = up + (1LL * r * r);
            }else {
                down = down + 1LL * (u - y) * r;
                up = up + 1LL * (y + r - u) * r;
            }
        }
        bool re = cmp(up,down);
        return re;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double r = 0;
        double l = 0;
        for(int i = 0;i < n;i++){
            auto x = squares[i];
            if(x[1] + x[2] > r){
                r = x[1] + x[2];
            }
        }
        while(fabs(l - r) > 1e-5){
            double mid = (l + r) / 2;
            if(check(squares,n,mid)) {
                l = mid;
            }else {
                r = mid;
            }
        }
        return l;
    }
};