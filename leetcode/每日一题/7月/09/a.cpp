#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> f(n,vector<int>(n));
        unordered_map<int,int> indices;
        for(int i = 0;i < n;i++){
            indices[arr[i]] = i;
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = i - 1;j >= 0;j--){
                int k = -1;
                if(indices.count(arr[i] - arr[j])){
                    k = indices[arr[i] - arr[j]];
                }
                if(k >= 0 && k < j){
                    f[j][i] = max(f[k][j] + 1,3);
                }
                if(k >= 0 && k < j)ans = max(ans,f[j][i]);
            }
        }
        return ans;
    }
};