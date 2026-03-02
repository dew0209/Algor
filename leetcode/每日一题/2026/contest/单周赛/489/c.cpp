
class Solution {
public:
    
    int almostPalindromic(string s) {
        int n = s.size();
        //f[i][j][1]:s[j.....i]能够形成的最大准回文子串
        //f[i][j][0]:s[j.....i]能够形成的最大回文子串
        //vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(2, 0))); //超时了，内存分配太慢
        vector<array<array<int, 2>, 2500>> f(n);
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = i;j >= 0;j--){
                if(i == j){
                    //单个字符是回文子串也是准回文子串
                    f[i][j][0] = 1;
                    f[i][j][1] = 1;
                }else {
                    
                    int& v = f[i][j][1];
                    //删除s[i]
                    v = max(v,f[i - 1][j][0] > 0 ? f[i - 1][j][0] + 1 : 0);
                    //删除s[j]
                    v = max(v,f[i][j + 1][0] > 0 ? f[i][j + 1][0] + 1 : 0);
                
                    if(s[i] == s[j]){
                        if(i - j > 1){
                            f[i][j][0] = max(f[i][j][0],f[i - 1][j + 1][0] > 0 ?  f[i - 1][j + 1][0] + 2 : 0);
                        } else {
                            f[i][j][0] = 2;
                        }
                        //s[i]和s[j]都不删除
                        v = max(v, f[i - 1][j + 1][1] > 0 ? f[i - 1][j + 1][1] + 2 : 0);
                    }
                }
                res = max(res,f[i][j][1]);
            }
        }
        return res; 
    }
};