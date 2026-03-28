//https://leetcode.cn/problems/matrix-similarity-after-cyclic-shifts/description/?envType=daily-question&envId=2026-03-27


class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> r(n,vector<int>(m,0));

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                
                int x = mat[i][j];
                if(i % 2 == 0){
                    r[i][((j - k) % m + m) % m] = x;
                }else {
                    r[i][((j + k) % m + m) % m] = x;
                }
            
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(r[i][j] != mat[i][j]){
                    return false;
                }
            }
            
        }
        return true;
    }
};