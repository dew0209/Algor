class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& m) {
        int n = m.size();
        vector<int> d(n,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(m[i][j] == 1){
                    d[i]++;
                    d[j]++;
                }
            }
        }
        for(int i = 0;i < n;i++)d[i] /= 2;
        return d;
    }
};