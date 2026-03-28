//https://leetcode.cn/problems/find-the-string-with-lcp/description/?envType=daily-question&envId=2026-03-28


class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n,'\0');
        int i = 0;
        for(char c = 'a';c <= 'z';c++){
            
            for(int j = i;j < n;j++){
                if(lcp[i][j]){
                    s[j] = c;
                }
            }
            while(i < n && s[i] != '\0'){
                i++;
            }
            if(i == n){
                break;
            }
        }
        if(i < n){
            return "";
        }
        
        
        //验证
        for(int i = n - 1;i >= 0;i--){
            for(int j = n - 1;j >= 0;j--){
                int v;
                if(i == n - 1 || j == n - 1){
                    v = s[i] == s[j] ? 1 : 0;
                }else {
                    v = s[i] == s[j] ? (lcp[i + 1][j + 1] + 1) : 0;
                }
                if(v != lcp[i][j]){
                    return "";
                }
            }
        }
        return s;
    }
};