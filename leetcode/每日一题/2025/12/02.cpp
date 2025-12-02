//https://leetcode.cn/problems/count-number-of-trapezoids-i/description/?envType=daily-question&envId=2025-12-02

class Solution {
public:
    int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int> cnt;
        int n = points.size();
        for(int i = 0;i < n;i++){
            int a = points[i][0];
            int b = points[i][1];
            cnt[b]++;
        }
        long long res = 0;
        long long sum = 0;
        for(auto [k,v] : cnt){
            res = (res + 1LL * v * (v - 1) / 2 * sum) % MOD;
            sum = (sum + 1LL * v * (v - 1) / 2) % MOD;
        }
        return (int)res;
    }
};