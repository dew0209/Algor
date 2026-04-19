//https://leetcode.cn/problems/maximum-distance-between-a-pair-of-values/description/?envType=daily-question&envId=2026-04-19



class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int res = 0;
        int j = -1;
        for(int i = 0;i < n;i++){
            while(j + 1 < m && nums1[i] <= nums2[j + 1])j++;
            if(j < m){
                res = max(j - i,res);
            }
        }
        return res;
    }
};