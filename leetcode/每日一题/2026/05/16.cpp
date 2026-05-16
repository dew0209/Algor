//https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=daily-question&envId=2026-05-16

class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = n - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums[mid] < nums[r]){
                r = mid;
            }else if(nums[mid] > nums[r]){
                l = mid + 1;
            }else {
                r -= 1;
            }
        }
        return nums[l];
    }
};