//题目链接：https://leetcode.cn/problems/design-neighbor-sum-service/description/?envType=daily-question&envId=2024-11-09



class NeighborSum {
public:
    vector<vector<int>> grids;
    NeighborSum(vector<vector<int>>& grid) {
        grids = grid;
    }
    
    int adjacentSum(int value) {
        
        int n = grids.size();

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){

                if(grids[i][j] == value){

                    int res = 0;
                    int a,b;
                    a = i - 1;b = j;
                    if(a >= 0 && a < n && b >= 0 && b < n){
                        res += grids[a][b];
                    }
                    a = i + 1;b = j;
                    if(a >= 0 && a < n && b >= 0 && b < n){
                        res += grids[a][b];
                    }
                    a = i;b = j - 1;
                    if(a >= 0 && a < n && b >= 0 && b < n){
                        res += grids[a][b];
                    }
                    a = i;b = j + 1;
                    if(a >= 0 && a < n && b >= 0 && b < n){
                        res += grids[a][b];
                    }
                    
                    return res;
                }

            }
        }
        return 0;
    }
    
    int diagonalSum(int value) {
        int n = grids.size();

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){

                if(grids[i][j] == value){

                    int res = 0;
                    int a,b;
                    a = i - 1;b = j - 1;
                    if(a >= 0 && a < n && b >= 0 && b < n){
                        res += grids[a][b];
                    }
                    a = i + 1;b = j + 1;
                    if(a >= 0 && a < n && b >= 0 && b < n){
                        res += grids[a][b];
                    }
                    a = i + 1;b = j - 1;
                    if(a >= 0 && a < n && b >= 0 && b < n){
                        res += grids[a][b];
                    }
                    a = i - 1;b = j + 1;
                    if(a >= 0 && a < n && b >= 0 && b < n){
                        res += grids[a][b];
                    }
                    
                    return res;
                }

            }
        }
        return 0;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */