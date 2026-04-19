//https://leetcode.cn/problems/smallest-stable-index-i/


class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int v = -1;
            for(int j = 0;j <= i;j++){
                v = max(v,nums[j]);
            }
            int w = 1e9;
            for(int j = i;j < n;j++){
                w = min(w,nums[j]);
            }
            //cout << v - w << endl;
            if(v - w <= k){
                return i;
            }
            
        }
        return -1;
    }
};