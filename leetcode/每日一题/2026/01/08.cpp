//https://leetcode.cn/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2026-01-08


class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> f(n + 1,vector<int>(m + 1,-0x3f3f3f3f3f));

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){

                int& v = f[i][j];
                
                if(i > 0){
                    v = max(f[i - 1][j],v);
                }
                if(j > 0){
                    v = max(f[i][j - 1],v);
                }

                if(i > 0 && j > 0){
                    v = max(f[i - 1][j - 1]  + nums1[i] * nums2[j],v);
                }

                v = max(nums1[i] * nums2[j],v);
            }
        }
        return f[n - 1][m - 1];
    }
};