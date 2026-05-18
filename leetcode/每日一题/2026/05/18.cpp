//https://leetcode.cn/problems/jump-game-iv/description/?envType=daily-question&envId=2026-05-18

class Solution {
public:

    int bfs(vector<int>& arr){
        queue<int> q;
        map<int,vector<int>> cnt;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            cnt[arr[i]].push_back(i);
        }
        vector<int> dist(n,-1);
        dist[0] = 0;
        q.push(0);
        while(q.size()){
            int t = q.front();
            q.pop();
            if(t == n - 1){
                return dist[t];
            }

            int a = t + 1;
            int b = t - 1;
            if(a >= 0 && a < n && dist[a] == -1){
                dist[a] = dist[t] + 1;
                q.push(a);
            }
            if(b >= 0 && b < n && dist[b] == -1){
                dist[b] = dist[t] + 1;
                q.push(b);
            }

            for(auto& idx : cnt[arr[t]]){
                if(dist[idx] == -1){
                    dist[idx] = dist[t] + 1;
                    q.push(idx);
                }
            }
            cnt[arr[t]].clear();
        }



        return -1;

    }

    int minJumps(vector<int>& arr) {
        return bfs(arr);
    }
};