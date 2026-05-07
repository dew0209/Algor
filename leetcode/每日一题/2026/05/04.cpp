//https://leetcode.cn/problems/rotate-image/description/?envType=daily-question&envId=2026-05-04

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.size();

        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n / 2; j++){
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};