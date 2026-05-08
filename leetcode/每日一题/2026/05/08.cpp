//https://leetcode.cn/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/?envType=daily-question&envId=2026-05-08

const int MAX_VAL = 1000010;
unordered_map<int,vector<int>> cnt;

int init = []{
        for(int i = 2;i <= MAX_VAL;i++){
            if(cnt[i].empty()){
                for(int j = i;j <= MAX_VAL;j += i){
                    cnt[j].push_back(i);
                }
            }

        }
        return 0;
}();

class Solution {
public:

    

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,vector<int>> group;

        for(int i = 0;i < n;i++){
            for(int u : cnt[nums[i]]){
                group[u].push_back(i);
            }
        }

        vector<int> dist(n,-1);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int t = q.front();
            q.pop();
            if(t == n - 1){
                return dist[t];
            }

            int u = t - 1;
            if(u >= 0 && dist[u] == -1){
                dist[u] = dist[t] + 1;
                q.push(u);
            }
            u = t + 1;
            if(u < n && dist[u] == -1){
                dist[u] = dist[t] + 1;
                q.push(u);
            }
            auto& pre = group[nums[t]];
            for(auto& id : pre){
                if(dist[id] == -1){
                    dist[id] = dist[t] + 1;
                    q.push(id);
                }
                
            }
            pre.clear();
        }
        return -1;
    }
};
