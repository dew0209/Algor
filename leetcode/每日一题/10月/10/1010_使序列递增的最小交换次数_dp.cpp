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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int a = 0,b = 1;
        for(int i = 1;i < n;i++){
            int at = a,bt = b;
            a = b = n;
            if(nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]){
                a = min(a,at);
                b = min(b,bt + 1);
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                a = min(a, bt);
                b = min(b, at + 1);
            }
        }
        return min(a,b);
    }
};