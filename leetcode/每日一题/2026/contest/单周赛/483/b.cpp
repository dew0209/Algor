//https://leetcode.cn/problems/word-squares-ii/description/


class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end());
        vector<vector<string>> res;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                for(int k = 0;k < n;k++){
                    for(int t = 0;t < n;t++){
                        if(i != j && i != k && i != t && j != k && j != t && k != t){
                            if(words[i][0] == words[j][0] && words[i][3] == words[k][0] && words[t][0] == words[j][3] && words[t][3] == words[k][3]){
                                vector<string> ans;
                                ans.push_back(words[i]);
                                ans.push_back(words[j]);
                                ans.push_back(words[k]);
                                ans.push_back(words[t]);
                                res.push_back(ans);
                            }
                        }
                    }
                    
                }
                
            }
            
        }
        
        return res;
    }
};