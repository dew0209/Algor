#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //区间dp
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

        //初始化
        for(int i = 0;i < ops.size();i += 2){
            dp[i][i].push_back(ops[i]);
        }
        //dp
        for(int len = 3;len <= ops.size();len += 2){
            for(int l = 0;l < ops.size();l += 2){
                int r = l + len - 1;
                if(r >= ops.size())break;
                for(int k = l + 1;k < r;k += 2){
                    auto left = dp[l][k - 1];
                    auto right = dp[k + 1][r];
                    for(auto &u : left){
                        for(auto &v : right){
                            if(ops[k] == -1){
                                dp[l][r].push_back(u + v);
                            }else if(ops[k] == -2){
                                dp[l][r].push_back(u - v);
                            }else {
                                dp[l][r].push_back(u * v);
                            }
                            
                        }
                    }
                }
            }
        }
        return dp[0][ops.size() - 1];
    }
};