//https://leetcode.cn/problems/rotating-the-box/description/?envType=daily-question&envId=2026-05-06

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        
        vector<vector<char>> res(m,vector<char>(n));
        for(int i = n - 1;i >= 0;i--){
                int last = m - 1;
                while(last >= 0 && boxGrid[i][last] == '*')last--;
                for(int j = m - 1;j >= 0;j--){
                    char c = boxGrid[i][j];
                    
                    if(c == '*'){
                        last = j - 1;
                    }else if(c == '#' && last >= 0){
                        swap(boxGrid[i][j],boxGrid[i][last]);
                        last--;
                    }
                }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res[j][n - 1 - i] = boxGrid[i][j];
            }
        }
        return res;
    }
};