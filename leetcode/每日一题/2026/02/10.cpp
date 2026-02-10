//https://leetcode.cn/problems/longest-balanced-subarray-i/?envType=daily-question&envId=2026-02-10

class Solution {
public:
   
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            set<int> a;
            set<int> b;
            for(int j = i;j < n;j++){
                if(nums[j] % 2 == 0){
                    a.insert(nums[j]);
                }else {
                    b.insert(nums[j]);
                }
                if(a.size() == b.size()){
                    res = max(res,j - i + 1);
                }
            }
        }
        return res;
    }
};