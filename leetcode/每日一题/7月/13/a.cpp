#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        int f[n];
        int idx = -1;
        for(int i = 0;i < n;i++){
            bool ok = true;
            while(ok && asteroids[i] < 0 && idx >= 0 && f[idx] > 0){
                ok = f[idx] < -asteroids[i];//是否存在
                if(f[idx] <= -asteroids[i]){
                    idx--;
                }
            }
            if(ok){
                f[++idx] = asteroids[i];
            }
        }
        vector<int> res;
        for(int i = 0;i <= idx;i++){
            res.push_back(f[i]);
        }
        return res;
    }
};