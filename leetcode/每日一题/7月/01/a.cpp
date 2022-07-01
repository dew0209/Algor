#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //记忆化搜索
    vector<int> dfs(vector<vector<vector<int>>>& dp,int l,int r,const vector<int>& ops){
        if(dp[l][r].empty()){
            if(l == r){
                dp[l][r].push_back(ops[l]);
            }else {
                for(int i = l;i < r;i += 2){
                    auto left = dfs(dp,l,i,ops);
                    auto right = dfs(dp,i + 2,r,ops);
                    for(auto &u : left){
                        for(auto &v : right){
                            if(ops[i + 1] == -1){
                                dp[l][r].push_back(u + v);
                            }else if(ops[i + 1] == -2){
                                dp[l][r].push_back(u - v);
                            }else {
                                dp[l][r].push_back(u * v);
                            }
                        }
                    }
                }
            }
        }
        return dp[l][r];
    }
    //记忆化搜索
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ops;
        //预处理：将每一个数和运算符抠出来
        for(int i = 0;i < expression.size();){
            if(!isdigit(expression[i])){
                if(expression[i] == '+'){
                    ops.push_back(-1);
                }else if(expression[i] == '-'){
                    ops.push_back(-2);
                }else {
                    ops.push_back(-3);
                }
                i++;
            }else {
                int t = 0;
                while(i < expression.size() && isdigit(expression[i])){
                    t = t * 10 + expression[i] - '0';
                    i++;
                }
                ops.push_back(t);
            }
        }
        vector<vector<vector<int>>> dp(ops.size(),vector<vector<int>>(ops.size()));
        return dfs(dp,0,ops.size() - 1,ops);
    }
};