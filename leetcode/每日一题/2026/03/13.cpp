//https://leetcode.cn/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/?envType=daily-question&envId=2026-03-13

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        long long l = 1,r = 0;
        int mv = 0;
        for(int i = 0;i < n;i++){
            mv = max(mv,workerTimes[i]);
        }
        r = 1LL * mv * mountainHeight * (mountainHeight + 1) / 2;
        cout << r << endl;
        while(l < r){
            long long mid = l + r >> 1;
            long long cnt = 0;
            for(auto t : workerTimes){
                long long work = mid / t;
                long long k = (-1.0 + sqrt(1 + work * 8)) / 2;
                cnt += k;
            }
            if(cnt >= mountainHeight){
                r = mid;
            }else {
                l = mid + 1;
            }
        }

        return l;
    }
};