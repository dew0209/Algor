//题目链接：https://leetcode.cn/problems/single-element-in-a-sorted-array/description/?envType=daily-question&envId=2024-11-10


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = n - 1;

        while(l < r){

            int mid = l + r >> 1;
            if(nums[mid] == nums[mid ^ 1]){
                l = mid + 1;
            }else {
                r = mid;
            }
        }
        return nums[l];
    }
};