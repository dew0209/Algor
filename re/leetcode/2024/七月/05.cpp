//题目链接：https://leetcode.cn/problems/modify-the-matrix/description/?envType=daily-question&envId=2024-07-05

//思路：暴力

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       vector<int> ans(m,0);
       vector<vector<int>> res(n,vector<int>(m,0));

       for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            res[j][i] = matrix[j][i];
            ans[i] = max(ans[i],matrix[j][i]);
        }
        for(int j = 0;j < n;j++){
            if(res[j][i] == -1){
                res[j][i] = ans[i];
            }
        }
       }
       return res;

    }
};