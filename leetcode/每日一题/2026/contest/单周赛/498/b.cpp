//https://leetcode.cn/problems/smallest-stable-index-ii/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n,-1);
        vector<int> right(n,1e9);
        int v = -1;
        for(int i = 0;i < n;i++){
            v = max(v,nums[i]);
            left[i] = v;
        }
        v = 1e9;
        for(int i = n - 1;i >= 0;i--){
            v = min(v,nums[i]);
            right[i] = v;
        }
        for(int i = 0;i < n;i++){
            if(left[i] - right[i] <= k){
                return i;
            }
        }
        return -1;
    }
};