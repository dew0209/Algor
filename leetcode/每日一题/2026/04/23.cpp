//https://leetcode.cn/problems/sum-of-distances/description/?envType=daily-question&envId=2026-04-23

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> cnt;
        for(int i = 0;i < n;i++){
            cnt[nums[i]].push_back(i);
        }
        //find
        vector<long long> res(n,0);
        for(auto& [x,y] : cnt){
            vector<long long> sum(y.size() + 1,0);

            for(int i = 0;i < y.size();i++){
                sum[i + 1] += sum[i] + y[i];
            }
            int last = 0;
            for(int i = 1;i <= y.size();i++){
                int id = y[i - 1];
                res[id] = (sum[y.size()] - sum[i]) - 1LL * id * (y.size() - i) + 1LL * id * (i - 1) - sum[i - 1];
            }
        }
        return res;
    }
};