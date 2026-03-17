//https://leetcode.cn/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2026-03-17

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> h(m,0);

        int ans = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                int x = matrix[i][j];
                if(x == 0){
                    h[j] = 0;
                }else {
                    h[j]++;
                }
            }
            vector<int> tempH = h;
            sort(tempH.begin(),tempH.end());
            for(int i = 0;i < m;i++){
                ans = max(ans,(m - 1 - i + 1) * tempH[i]);
            }
        }
        return ans;
    }
};