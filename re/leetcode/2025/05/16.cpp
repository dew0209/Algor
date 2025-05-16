//https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii/description/?envType=daily-question&envId=2025-05-16

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> f(n + 10,1);
        vector<int> pre(n + 10,0);

        for(int i = 0;i < n;i++){
            pre[i] = i;
        }

        int maxId = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(groups[i] != groups[j] && check(words[i],words[j])){
                    if(f[i] < f[j] + 1){
                        f[i] = f[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if(f[i] > f[maxId]){
                maxId = i;
            }
        }
        vector<string> res;
        while(true){
            res.push_back(words[maxId]);
            if(maxId == pre[maxId])break;
            maxId = pre[maxId];
        }
        reverse(res.begin(),res.end());
        return res;
    }

    bool check(string& s1,string& s2){
        if(s1.size() != s2.size())return false;
        int dif = 0;
        for(int i = 0;i < s1.size();i++){
            if(s1[i] != s2[i]){
                dif++;
                if(dif > 1)break;
            }
        }
        return dif == 1;
    }

};