//https://leetcode.cn/problems/special-positions-in-a-binary-matrix/?envType=daily-question&envId=2026-03-04

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> a(n,0);
        vector<int> b(m,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 1){
                    a[i]++;
                    b[j]++;
                }
            }
        }
        int r = 0;
        for(int i = 0;i < n;i++){
            if(a[i] != 1){
                continue;
            }
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 1){
                    if(b[j] == 1){
                        r++;
                    }
                }
            }
        }
        return r;
    }
};