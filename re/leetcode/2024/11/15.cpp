//题目链接：https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/?envType=daily-question&envId=2024-11-15

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int a = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i < n;i++){
            int l = 0 ,r = m - 1;
            while(l < r){
                if(grid[i][l] != grid[i][r]){
                    a++;
                }
                l++;
                r--;
            }
        }
        int b = 0;
        for(int i = 0;i < m;i++){
            int top = 0;
            int bot = n - 1;
            while(top < bot){
                if(grid[top][i] != grid[bot][i]){
                    b++;
                }
                top++;
                bot--;
            }
        }
        return min(a,b);
    }
};