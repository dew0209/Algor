//https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/solutions/

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> cnt1 = build(edges1,k);
        vector<int> cnt2 = build(edges2,k - 1);

        int maxCnt = *max_element(cnt2.begin(),cnt2.end());
        vector<int> res(n);

        for(int i = 0;i < n;i++){
            res[i] = cnt1[i] + maxCnt;
        }
        return res;
    }
    vector<int> build(vector<vector<int>>& edges,int k){
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for(auto edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n);
        for(int i = 0;i < n;i++){
            res[i] = dfs(i,-1,g,k);
        }
        return res;
    }

    int dfs(int u,int fa,vector<vector<int>>& g,int k){
        if(k < 0){
            return 0;
        }
        int res = 1;
        for(auto t : g[u]){
            if(t == fa)continue;
            res += dfs(t,u,g,k - 1);
        }
        return res;
    }

};