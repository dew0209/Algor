//题目连接：https://leetcode.cn/problems/find-a-good-subset-of-the-matrix/description/?envType=daily-question&envId=2024-06-25
//思路：贪心

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> res;
        map<int,int> mp;

        for(int i = 0;i < n;i++){
            int st = 0;
            for(int j = 0;j < m;j++){
                st = st | (grid[i][j] << j);
            }
            mp[st] = i;
        }
        if(mp.count(0)){
            res.push_back(mp[0]);
            return res;
        }
        for(auto [x,i] : mp){
            for(auto [y,j] : mp){
                if(!(x & y)){
                    return {min(i,j),max(i,j)};
                }
            }
        }
        return res;
    }
};