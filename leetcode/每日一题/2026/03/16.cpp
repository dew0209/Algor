//https://leetcode.cn/problems/get-biggest-three-rhombus-sums-in-a-grid/description/?envType=daily-question&envId=2026-03-16

class Solution {
public:

    void setRes(vector<int>& res,int area){
        if(area > res[0]){
            res[2] = res[1];
            res[1] = res[0];
            res[0] = area;
        }else if(area != res[0] && area > res[1]){
            res[2] = res[1];
            res[1] = area;
        }else if(area != res[1] && area != res[0] && area > res[2]){
            res[2] = area;
        }
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> sum1(n + 1,vector<int>(m + 2,0));
        vector<vector<int>> sum2(n + 1,vector<int>(m + 2,0));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                sum1[i][j] = grid[i - 1][j - 1] + sum1[i - 1][j - 1];
                sum2[i][j] = grid[i - 1][j - 1] + sum2[i - 1][j + 1];
            }
        }
        vector<int> res(3,0);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                //单点
                setRes(res,grid[i][j]);
                for(int k = i + 2;k < n;k += 2){
                    //上
                    int ux = i,uy = j;
                    //下
                    int dx = k,dy = j;
                    //左
                    int lx = (i + k) / 2,ly = j - (k - i) / 2;
                    //右
                    int rx = (i + k) / 2,ry = j + (k - i) / 2;
                    if(ly < 0 || ry >= m){
                        break;
                    }

                    //计算结果：

                    int area = (sum2[lx + 1][ly + 1] - sum2[ux][uy + 2]) + 
                                (sum1[rx + 1][ry + 1] - sum1[ux][uy]) + 
                                (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) + 
                                (sum1[dx + 1][dy + 1] - sum1[lx][ly]) - 
                                (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] + grid[rx][ry]);

                    setRes(res,area);
                }

            }
        }
        vector<int> ans;
        for(auto c : res){
            if(c){
                ans.push_back(c);
            }
        }
        return ans;
    }
};