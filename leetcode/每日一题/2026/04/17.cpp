//https://leetcode.cn/problems/minimum-absolute-distance-between-mirror-pairs/description/?envType=daily-question&envId=2026-04-17

class Solution {
public:
    int get_num(int u){
        if(u == 0)return 0;
        vector<int> num;
        while(u){
            num.push_back(u % 10);
            u /= 10;
        }
        reverse(num.begin(),num.end());
        //去掉0
        while(num.size() > 1 && num.back() == 0)num.pop_back();
        int res = 0;
        for(int i = num.size() - 1;i >= 0;i--){
            res = res * 10 + num[i];
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        map<int,int> cnt;
        int ans = n + 1;
        for(int i = 0;i < n;i++){
            int res = get_num(nums[i]);
            if(cnt.contains(nums[i])){
                ans = min(ans,i - cnt[nums[i]]);                
            }
            cnt[res] = i;
        }
        if(ans == n + 1){
            ans = -1;
        }
        return ans;
    }
};