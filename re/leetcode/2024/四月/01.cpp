题目链接：https://leetcode.cn/problems/faulty-keyboard/description/

思路：遍历

代码：

class Solution {
public:
    string turn(string s){
        string res = "";
        for(int i = s.size() - 1;i >= 0;i--){
            res = res + s[i];
        }
        return res;
    }
    string finalString(string s) {
        string res = "";
        int n = s.size();
        for(int i = 0;i < n;i++){
            if(s[i] == 'i'){
                res = turn(res);
            }else {
                res = res + s[i];
            }
        }
        return res;
    }
};