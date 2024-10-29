//题目链接：https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/description/?envType=daily-question&envId=2024-10-29


class Solution {
public:

    void dfs(vector<string> &res,int len,string str,int tol){
        if(len == tol){
            res.push_back(str);
            return ;
        }
        //可以无脑塞1
        dfs(res,len + 1,str + "1",tol);
        if(len == 0 || str[len - 1] == '1'){
            dfs(res,len + 1,str + "0",tol);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        dfs(res,0,"",n);
        return res;
    }
};