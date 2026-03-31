//https://leetcode.cn/problems/lexicographically-smallest-generated-string/

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string s(n + m - 1,'a');
        vector<int> visted(n + m - 1,0);
        for(int i = 0;i < n;i++){
            if(str1[i] == 'T'){
                for(int j = i;j <= i + m - 1;j++){
                    if(visted[j] && s[j] != str2[j - i]){
                        return "";
                    }else {
                        visted[j] = 1;
                        s[j] = str2[j - i];
                    }
                }

            }
        }

        for(int i = 0;i < n;i++){
            if(str1[i] == 'F'){
                bool flag = false;
                int idx = -1;
                for(int j = i + m - 1;j >= i;j--){
                    if(s[j] != str2[j - i]){
                        flag = true;
                    }
                    if(idx == -1 && !visted[j]){
                        idx = j;
                    }
                }
                if(flag){
                    continue;
                }else if(idx != -1){
                    s[idx] = 'b';
                }else {
                    return "";
                }

            }
        }
        return s;

    }
};