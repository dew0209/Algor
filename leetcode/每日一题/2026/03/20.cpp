//https://leetcode.cn/problems/minimum-absolute-difference-in-sliding-submatrix/?envType=daily-question&envId=2026-03-20

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res(n - k + 1,vector(m - k + 1,0));

        for(int i = 0;i < n - k + 1;i++){
            for(int j = 0;j < m - k + 1;j++){
                
                int re = 1e9;

                map<int,int> cnt;

                for(int x = i;x < i + k;x++){
                    for(int y = j;y < j + k;y++){
                        cnt[grid[x][y]]++;
                    }
                }

                for(auto& [t1,_] : cnt){
                    for(auto& [t2,_] : cnt){
                        if(t1 != t2){
                            re = min(re,abs(t1 - t2));
                        }
                    }
                }
                if(re == 1e9){
                    re = 0;
                }
                res[i][j] = re;
            }
        }
        return res;
    }
};