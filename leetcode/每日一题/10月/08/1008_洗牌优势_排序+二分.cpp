#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>

typedef long long LL;

#define fi first
#define se second

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        //排序
        sort(nums1.begin(),nums1.end());
        vector<int> res;
        //标记数组
        vector<int> st(n,0);
        for(int i = 0;i < m;i++){
            //寻找的值
            int x = nums2[i];
            //找到大于其的最小值
            int l = 0,r = n - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(nums1[mid] > x)r = mid;
                else l = mid + 1;
            }
            //检查是否有效并且是否大于x
            int k = 0;
            if(l >= n || nums1[l] <= x){
                while(k < n && st[k])k++;
            }else {
                k = l;
                while(k < n && st[k])k++;
                //没有了，从头开始找最小的
                if(k >= n || st[k]){
                    k = 0;
                    while(st[k] && k < n)k++;
                }
            }
            //标记
            st[k] = 1;
            //cout << k << "----" << x << endl;
            res.push_back(nums1[k]);
        }
        return res;
    }
};