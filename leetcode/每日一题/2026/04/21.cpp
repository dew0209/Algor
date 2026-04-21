//https://leetcode.cn/problems/minimize-hamming-distance-after-swap-operations/description/?envType=daily-question&envId=2026-04-21

class Solution {
public:
    int p[100010];
    int find(int u){
        if(p[u] != u){
            p[u] = find(p[u]);
        }
        return p[u];
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int m = allowedSwaps.size();
        for(int i = 0;i < n;i++)p[i] = i;
        for(int i = 0;i < m;i++){
            int a = allowedSwaps[i][0];
            int b = allowedSwaps[i][1];
            a = find(a);
            b = find(b);
            p[a] = b;
        }
        map<int,vector<int>> cnt1;
        map<int,vector<int>> cnt2;
        for(int i = 0;i < n;i++){
            int x = find(i);
            int u = source[i];
            int t = target[i];
            cnt1[x].push_back(u);
            cnt2[x].push_back(t);
        }
        int res = 0;

        for(auto& [x,y1] : cnt1){
            auto y2 = cnt2[x];
            map<int,int> count;
            for(int i = 0;i < y1.size();i++){
                count[y1[i]]++;
                count[y2[i]]--;
            }
            int sum = 0;
            for(auto& [xx,yy] : count){
                if(yy != 0){
                    sum += abs(yy);
                }
            }
            res += (sum / 2);
        }
        return res;

    }
};