//题目链接：https://leetcode.cn/problems/accounts-merge/description/?envType=daily-question&envId=2024-07-15
//思路：并查集

const int N = 10010;

class Solution {
public:
    int f[N];

    int find(int u){
        if(f[u] != u)f[u] = find(f[u]);
        return f[u];
    }

    string names[N];
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i = 1;i < N;i++)f[i] = i;
        int len = 0;
        map<string,int> cnt;
        map<int,string> q;
        for(auto accs : accounts){
            string na = accs[0];
            for(int i = 1;i < accs.size();i++){
                string em = accs[i];
                if(!cnt.count(em)){
                    cnt[em] = ++len;
                    q[len] = em;
                }
                int u = cnt[em];
                names[u] = na;
            }
        }
        //合并
        for(auto accs : accounts){
            int a = find(cnt[accs[1]]);
            for(int i = 2;i < accs.size();i++){
                string em = accs[i];
                int b = find(cnt[em]);
                if(a != b){
                    f[b] = a;
                }
            }
        }
        map<int,vector<string>> ans;
        for(int i = 1;i <= len;i++){
            string em = q[i];
            int fa = find(i);
            vector<string>& se = ans[fa];
            se.emplace_back(em);
        }
        vector<vector<string>> res;
        for(auto [x,ems] : ans){
            sort(ems.begin(),ems.end());
            string na = names[x];
            vector<string> aaaa;
            aaaa.emplace_back(na);
            for(auto c : ems){
                aaaa.emplace_back(c);
            }
            res.emplace_back(aaaa);
        }
        return res;
    }
};