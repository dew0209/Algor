题目链接：https://leetcode.cn/problems/minimum-absolute-difference-between-elements-with-constraint/

方法一：二分

在某个区间内，找到最接近x的上下界。也就是找一个最大的小等于x的数，找一个最小的大于等于x的数。

利用set，c++set是有序的

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> h;
        int n = nums.size();
        int res = 0x3f3f3f3f;
        for(int i = x;i < n;i++){
            h.insert(nums[i - x]);
            //找到最小的大于等于x的数
            auto t = h.lower_bound(nums[i]);
            if(t != h.end()){
                res = min(res,abs(*t - nums[i]));
            }
            //前面一个就是最大的小于等于x的数
            if(t != h.begin()){
                res = min(res,abs(*prev(t) - nums[i]));
            }
        }
        return res;
    }
};