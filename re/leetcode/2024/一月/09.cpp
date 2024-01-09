题目链接：https://leetcode.cn/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-01-09

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        map<string,int> cnt;
        for(auto& str : dictionary){
            cnt[str]++;
        }
        vector<int> d(110,0);
        for(int i = 1;i <= s.size();i++){

            d[i] = d[i - 1] + 1;
            for(int j = i - 1;j >= 0;j--){
                if(cnt.count(s.substr(j,i - j))){
                    d[i] = min(d[i],d[j]);
                }
            }

        }
        return d[s.size()];
    }
};