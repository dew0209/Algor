//https://leetcode.cn/problems/minimum-common-value/description/?envType=daily-question&envId=2026-05-19

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> cnt;
        for(auto& num : nums1){
            cnt.insert(num);
        }
        int res = -1;
        for(auto& num : nums2){
            if(cnt.contains(num)){
                
                if(res == -1){
                    res = num;
                }else {
                    res = min(num,res);
                }

            }
        }
        return res;
        
    }
};