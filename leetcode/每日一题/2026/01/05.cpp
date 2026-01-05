//https://leetcode.cn/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> a;
        vector<int> b;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] < 0){
                    a.push_back(matrix[i][j]);
                }else {
                    b.push_back(matrix[i][j]);
                }
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(a.begin(),a.end());

        if(a.size() % 2){
            if(b.size() != 0){
                if(abs(a[0]) > b[0]){
                    a[0] *= -1;
                    b[0] *= -1;
                }
            }
        }
        long long res = 0;

        for(int i = a.size() - 1;i >= 0;i--){
            if(i != 0 || a.size() % 2 == 0){
                res = res + a[i] * -1;
            }else {
                res = res + a[i];
            }
        }

        for(int i = b.size() - 1;i >= 0;i--){
            res = res + b[i];
        }
        return res;
    }
};