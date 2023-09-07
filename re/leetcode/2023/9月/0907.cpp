题目链接：https://leetcode.cn/problems/minimum-time-to-repair-cars/description/

方法一：二分查找


class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1,r = 1LL * ranks[0] * cars * cars;
        auto check = [&](long long m){
            long long res = 0;
            for(auto x : ranks){
                res += sqrt(m / x);
            }
            return res >= cars;
        };
        while(l < r){
            long long mid = l + r >> 1;
            if(check(mid)){
                r = mid;
            }else l = mid + 1;
        }
        return l;
    }
};