//题目连接：https://leetcode.cn/problems/find-common-elements-between-two-arrays/description/?envType=daily-question&envId=2024-07-16


class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int a = 0;
        int b = 0;
        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0;i < n;i++){
            int v = nums1[i];
            for(int j = 0;j < m;j++){
                if(nums2[j] == v){
                    a++;
                    break;
                }
            }
        }
        for(int i = 0;i < m;i++){
            int v = nums2[i];
            for(int j = 0;j < n;j++){
                if(nums1[j] == v){
                    b++;
                    break;
                }
            }
        }
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};