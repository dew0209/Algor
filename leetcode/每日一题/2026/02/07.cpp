//https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2026-02-07

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> f(n + 1,0);
        int count = 0;
        for(int i = 1;i <= n;i++){
            char x = s[i - 1];
            if(x == 'b'){
                count++;
                f[i] = f[i - 1];
            }else {
                f[i] = min(f[i - 1] + 1,count);
            }
        }
        return f[n];
    }
};