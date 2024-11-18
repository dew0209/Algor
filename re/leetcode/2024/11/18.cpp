//题目链接：https://leetcode.cn/problems/image-smoother/description/?envType=daily-question&envId=2024-11-18


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        
        vector<vector<int>> res(n,vector<int>(m,0));

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                
                int sum = 0;
                int t = 0;
                for(int k = -1;k <= 1;k++){
                    for(int v = -1;v <= 1;v++){
                        
                        int x = i + k;
                        int y = j + v;
                        if(x < 0 || x >= n)continue;
                        if(y < 0 || y >= m)continue;
                        sum = sum + img[x][y];
                        t++;
                        
                    }
                }
                res[i][j] = sum / t;
            }
        }
        return res;
    }
};