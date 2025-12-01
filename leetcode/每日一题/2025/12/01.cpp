//https://leetcode.cn/problems/maximum-running-time-of-n-computers/description/?envType=daily-question&envId=2025-12-01

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0,r = 0;
        for(auto batterie : batteries){
            r += batterie;
        }
        while(l < r){
            long long mid = (l + r + 1) / 2;
            long long s = 0;
            for(auto batterie : batteries){
                s += min(1LL * batterie,mid);
            }

            if(s >= mid * n){
                l = mid;
            }else {
                r = mid - 1;
            }

        }
        return l;

    }
};