//https://leetcode.cn/problems/minimum-distance-between-three-equal-elements-ii/?envType=daily-question&envId=2026-04-11

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> cnt;
        for(int i = 0;i < nums.size();i++){
            cnt[nums[i]].push_back(i);
        }
        int res = 1e9;
        for(auto& [x,y] : cnt){
            if(y.size() >= 3){
                sort(y.begin(),y.end());
                for(int i = 1;i < y.size() - 1;i++){
                    res = min(res,y[i] - y[i - 1] + y[i + 1] - y[i - 1] + y[i + 1] - y[i]);
                }
            }
        }
        if(res == 1e9){
            res = -1;
        }
        return res;
    }
};