//https://leetcode.cn/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/?envType=daily-question&envId=2026-03-22

int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
class Solution {
public:
    bool check(vector<vector<int>>& a,vector<vector<int>>& b,int n){

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(a[i][j] != b[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int u = 0;u < 4;u++){
            vector<vector<int>> me(n,vector<int>(n,0));
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    me[j][n-1-i] = mat[i][j];  // 顺时针旋转90度
                }
            }
            if(check(me,target,n)){
                return true;
            }
            mat = me;
        }
        return false;
    }
};