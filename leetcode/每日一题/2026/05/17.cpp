//https://leetcode.cn/problems/jump-game-iii/description/?envType=daily-question&envId=2026-05-17

class Solution {
public:

    bool bfs(vector<int>& arr, int start){
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<int> dist(n,0);
        dist[start] = 1;
        while(q.size()){
            int t = q.front();            
            q.pop();
            if(arr[t] == 0){
                return true;
            }
            int a = t - arr[t];
            int b = t + arr[t];
            if(a >= 0 && a < n && !dist[a]){
                q.push(a);
                dist[a] = true;
            }
            if(b >= 0 && b < n && !dist[b]){
                q.push(b);
                dist[b] = true;
            }
        }
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        return bfs(arr,start);
    }
};