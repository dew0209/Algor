//https://leetcode.cn/problems/closest-equal-element-queries/description/?envType=daily-question&envId=2026-04-16


class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int,vector<int>> cnt;
        for(int i = 0;i < n;i++){
            cnt[nums[i]].push_back(i);
        }
        
        for (auto& [_, pos] : cnt) {
            int x = pos[0];
            pos.insert(pos.begin(), pos.back() - n);
            pos.push_back(x + n);
        }

        int m = queries.size();
        for(int i = 0;i < m;i++){
            if(cnt[nums[queries[i]]].size() > 3){
                int pos = lower_bound(cnt[nums[queries[i]]].begin(), cnt[nums[queries[i]]].end(), queries[i]) - cnt[nums[queries[i]]].begin();
                queries[i] = min(cnt[nums[queries[i]]][pos + 1] - cnt[nums[queries[i]]][pos], cnt[nums[queries[i]]][pos] - cnt[nums[queries[i]]][pos - 1]);
            }else {
                queries[i] = -1;
            }
        }
        return queries;
    }
};