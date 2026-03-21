//https://leetcode.cn/problems/flip-square-submatrix-vertically/description/?envType=daily-question&envId=2026-03-21

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int ax = x,bx = x + k - 1;ax < x + k && ax < bx;ax++,bx--){
            for(int ay = y,by = y;by < y + k;ay++,by++){
                swap(grid[ax][ay],grid[bx][by]);
            }
        }
        return grid;
    }
};