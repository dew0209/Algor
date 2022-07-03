#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> cnt(n);
        for(int i = 1;i < n;i++){
            cnt[i] = arr[i] - arr[i - 1];
        }
        int d = INT_MAX;
        for(int i = 1;i < n;i++){
            d = min(abs(cnt[i]),d);
        }
        vector<vector<int>> res;
        for(int i = 1;i < n;i++){
            if(abs(cnt[i]) == d){
                res.push_back({arr[i - 1],arr[i]});
            }
        }
        return res;
    }
};