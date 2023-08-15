题目链接：https://leetcode.cn/problems/find-and-replace-in-string/description/

方法一：模拟（暴力）

string res;
for(int i = 0;i < n;i++){
    if(s.substr(...) == source[id]){
        存在：res += targets[id];
    }
    不存在：当前元素s[i]直接加到结果集。（从小到大排序）
}

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        int m = indices.size();
        vector<int> p(m,0);
        iota(p.begin(),p.end(),0);
        sort(p.begin(),p.end(),[&](const int i,const int j){return indices[i] < indices[j];});
        int id = 0;
        string res;
        for(int i = 0;i < n;){
            while(id < m && indices[p[id]] < i)id++;
            int ok = 0;
            if(id < m && indices[p[id]] == i){
                if(s.substr(i,sources[p[id]].size()) == sources[p[id]]){
                    ok = 1;
                }
            }
            if(ok){
                res += targets[p[id]];
                i += sources[p[id]].size();
            }else {
                res += s[i];
                i++;
            }

        }
        return res;
    }
};


方法二：模拟（线性的）


假设每个位置都能替换，替换自己
abcd

记为：p
[0,{"eee","ab".size()}]
[1,{"",1}]
[2,{"ffff","ec".size()}]
[3,{"",1}]

p[indices[i]]要变化
[0,2]
["ab","ec"]
["eee","ffff"]


class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        vector<pair<string,int>> p(n,{"",1});
        for(int i = 0;i < indices.size();i++){
            if(s.compare(indices[i],sources[i].size(),sources[i]) == 0){
                p[indices[i]] = {targets[i],sources[i].size()};
            }
        }
        string res;
        for(int i = 0;i < n;i += p[i].second){
            if(p[i].first.empty()){
                res += s[i];
            }else {
                res += p[i].first;
            }
        }
        return res;
    }
};