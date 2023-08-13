题目链接：https://leetcode.cn/problems/merge-sorted-array/description/

方法一：暴力

nums1:[1,2,3,0,0,0]  3
nums2:[2,5,6] 3

开额外空间
vector<int> a;

int i = 0,j = 0;
if(nums1[i] < nums2[j])a.push_back(nums1[i++]);
else a.push_back(nums2[j++]);


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> a;
        int i = 0,j = 0;
        for(i = 0,j = 0;i < m && j < n;){
            if(nums1[i] > nums2[j])a.push_back(nums2[j++]);
            else a.push_back(nums1[i++]);
        }
        //这里需要处理没有比较的数据
        while(i < m)a.push_back(nums1[i++]);
        while(j < n)a.push_back(nums2[j++]);
        for(int i = 0;i < n + m;i++){
            nums1[i] = a[i];
        }
    }
};


方法二：
nums1:[1,2,3,0,0,0]  3
nums2:[2,5,6] 3
    m - 1 id
1 2 3 0 0 0
    n - 1
2 5 6



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int id = n + m - 1;
        n--;
        m--;
        while(n >= 0){
            while(m >= 0 && nums1[m] > nums2[n]){
                swap(nums1[m--],nums1[id--]);
            }

            swap(nums1[id--],nums2[n--]);
        }
    }
};