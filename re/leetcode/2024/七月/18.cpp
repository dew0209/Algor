//题目连接：https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes/description/?envType=daily-question&envId=2024-07-18


//dijkstr


typedef pair<int,int> PII;
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<PII>> roads(n);
        for(auto& road : edges){
            int x = road[0];
            int y = road[1];
            int z = road[2];
            roads[x].push_back({y,z});
            roads[y].push_back({x,z});
        }
        vector<int> res(n,-1);
        res[0] = 0;
        vector<bool> st(n,false);
        priority_queue<PII,vector<PII>,greater<PII>> q;
        q.push({0,0});
        while(q.size()){
            auto t = q.top();
            q.pop();
            int u = t.second,distance = t.first;
            if(st[u])continue;
            st[u] = true;
            for(auto& road : roads[u]){
                int v = road.first;
                int dist = road.second + distance;
                if(dist < disappear[v] && (res[v] == -1 || res[v] > dist)){
                    res[v] = dist;
                    q.push({dist,v});
                }
            }
        }
        return res;
    }
};