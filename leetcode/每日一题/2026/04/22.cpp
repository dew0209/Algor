//https://leetcode.cn/problems/words-within-two-edits-of-dictionary/description/?envType=daily-question&envId=2026-04-22

class Solution {
public:

    bool check(string& source,vector<string>& dictionary){
        int m = source.size();
        int n = dictionary.size();
        for(int i = 0;i < n;i++){
            string& dict = dictionary[i];
            int count = 0;
            for(int j = 0;j < m;j++){
                if(source[j] != dictionary[i][j]){
                    count++;
                    if(count > 2){
                        break;
                    }
                }
            }
            if(count <= 2){
                return true;
            }
        }
        return false;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        vector<int> cnt(n,0);
        vector<string> res;
        for(int i = 0;i < n;i++){
            if(check(queries[i],dictionary)){
                res.push_back(queries[i]);
            }
        }
        return res;
    }
};