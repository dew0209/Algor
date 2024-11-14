//题目链接：https://leetcode.cn/problems/count-the-number-of-good-nodes/?envType=daily-question&envId=2024-11-14


class Solution {
public:
    int ans = 0;
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> w(n + 10);
        for(auto ed : edges){
            int a = ed[0];
            int b = ed[1];
            w[a].push_back(b);
            w[b].push_back(a);
        }
        dfs(w,0,-1);
        return ans;
    }

    int dfs(vector<vector<int>>& w,int u,int fa){
        int sum = 1;
        int cnt = 0;
        bool ok = true;
        for(auto v : w[u]){
            if(v != fa){
                int s = dfs(w,v,u);
                if(cnt == 0){
                    cnt = s;
                }else if(cnt != s){
                    ok = false;
                }
                sum += s;
            }
        }
        if(ok){
            ans++;
        }
        return sum;
    }

};