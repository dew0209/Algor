//https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2026-03-05

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        vector<vector<int>> f(n,vector<int>(2,0));
        for(int i = 0;i < n;i++){
            char c = s[i];
            if(i == 0){
                if(c == '0'){
                    f[0][0] = 0;
                    f[0][1] = 1;
                }else {
                    f[0][0] = 1;
                    f[0][1] = 0;
                }
            }else {
                if(c == '0'){
                    f[i][0] = f[i - 1][1];
                    f[i][1] = 1 + f[i - 1][0];
                }else {
                    f[i][1] = f[i - 1][0];
                    f[i][0] = 1 + f[i - 1][1];
                }
            }
        }
        return min(f[n - 1][0],f[n - 1][1]);
    }
};