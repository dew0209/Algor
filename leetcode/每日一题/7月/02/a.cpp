#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> f(n + 1);
        f[0] = startFuel;
        for(int i = 0;i < n;i++){
            for(int j = i;j >= 0;j--){
                if(f[j] >= stations[i][0]){
                    f[j + 1] = max(f[j + 1],f[j] + stations[i][1]); 
                }
            }
        }
        for(int i = 0;i <= n;i++){
            if(f[i] >= target)return i;
        }
        return -1;
    }
};