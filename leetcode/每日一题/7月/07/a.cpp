#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> spilt(string sentence,char ch){
        vector<string> res;
        int i = 0;
        while(i < sentence.size()){
            while(i < sentence.size() && sentence[i] == ch){
                i++;
            }
            int j = i;
            while(j < sentence.size() && sentence[j] != ch){
                j++;
            }
            res.push_back(sentence.substr(i,j - i));
            i = j;
        }
        return res;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dictionarySet;
        for(auto &c : dictionary){
            dictionarySet.insert(c);
        }
         vector<string> words = spilt(sentence,' ');

         for(auto &s : words){
             for(int i = 0;i < s.size();i++){
                 if(dictionarySet.count(s.substr(0,1 + i))){
                     s = s.substr(0,1 + i);
                 }
             }
        }
        string ans = "";
        for(int i = 0;i < words.size();i++){
            if(i != words.size() - 1){
                ans += words[i] + " ";
            }else {
                ans += words[i];
            }
        }
        return ans;
    }
};