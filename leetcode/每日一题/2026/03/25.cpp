//

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                sum += grid[i][j];
            }
        } 
        if(sum % 2)return false;
        long long ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                ans += grid[i][j];
            }
            if(ans == sum / 2){
                return true;
            }
        }

        ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                ans += grid[j][i];
            }
            if(ans == sum / 2){
                return true;
            }
        }

        return false;
    }
};