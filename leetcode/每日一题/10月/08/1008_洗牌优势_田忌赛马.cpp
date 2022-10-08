#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(n);
        int ids[n];
        sort(nums1.begin(),nums1.end());
        iota(ids,ids + n,0);
        sort(ids,ids + n,[&](int i,int j){return nums2[i] < nums2[j];});
        int l = 0,r = n - 1;
        for(int i = 0;i < n;i++){
            int x = nums1[i];
            res[x > nums2[ids[l]] ? ids[l++] : ids[r--]] = x;
        }
        return res;
    }
};