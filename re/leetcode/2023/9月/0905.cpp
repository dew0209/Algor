题目链接：https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays/


方法一：暴力

结果：
    可能1：单个数字，在两个数组里面都出现过
    可能2：两个数字，分别由nums1和nums2中最小的数字组成

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int cnt[10];
        for(int i = 0;i < n;i++){
            cnt[nums1[i]] = 1;
        }
        int mi = 10;
        int re = 10;
        for(int i = 0;i < m;i++){
            int x = nums2[i];
            if(cnt[x] == 1){
                re = min(re,x);
            }
            mi = min(mi,x);
        }
        if(re != 10)return re;
        int ni = 10;
        for(int i = 0;i < 10;i++){
            if(cnt[i] == 1){
                ni = i;
                break;
            }
        }
        return mi > ni ? ni * 10 + mi : mi * 10 + ni;
    }
};