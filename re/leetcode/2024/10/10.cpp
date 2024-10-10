//题目链接：https://leetcode.cn/problems/find-the-number-of-good-pairs-i/?envType=daily-question&envId=2024-10-10

//暴力模拟

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       int n = nums1.size();
       int m = nums2.size();
       int res = 0;
       for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(nums1[i] % (nums2[j] * k) == 0){
                    res++;
                }
            }
       } 
       return res;
    }
};

//枚举因子

/*
    nums1[i] = nums2[j] * k * d
    nums1[i] / k = nums2[j] * d
    也就是说：nums2[j]是nums1[i] / k 的一个因子。
    nums1[i] / k 枚举因子，统计计数。
*/

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       int n = nums1.size();
       int m = nums2.size();
       int res = 0;
       for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(nums1[i] % (nums2[j] * k) == 0){
                    res++;
                }
            }
       } 
       return res;
    }
};