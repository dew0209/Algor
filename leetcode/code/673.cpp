#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2010;

int len[N];
int total[N];

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < 2010;i++){
            len[i] = 1;
            total[i] = 1;
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i]){
                    if(len[j] >= len[i]){
                        total[i] = total[j];
                        len[i] = len[j] + 1;
                    } else if(len[j] + 1 == len[i]){
                        total[i] += total[j];
                    }
                }
            }
        }
        int maxres = 0;
        for(int i = 0;i < n;i++){
            maxres = max(maxres,len[i]);
        }
        int res = 0;
        for(int i = 0;i < n;i++){
            if(maxres == len[i]){
                res += total[i];
            }
        }
        return res;
    }
};