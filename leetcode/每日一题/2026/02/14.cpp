//https://leetcode.cn/problems/champagne-tower/description/?envType=daily-question&envId=2026-02-14


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> a;
        a.push_back(poured);
        for(int i = 1;i <= query_row;i++){
            vector<double> b(i + 1,0);
            for(int j = 0;j < a.size();j++){
                double x = a[j];
                if(x > 1){
                    b[j] += (x - 1) / 2;
                    b[j + 1] += (x - 1) / 2;
                }
            }
            a = b;
        }
        return min(1.0,a[query_glass]);
    }

};