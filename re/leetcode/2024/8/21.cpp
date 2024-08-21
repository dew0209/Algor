class Solution {
public:
    long long accumulatedBitPrice(int x, long long num) {
        long long period = 1LL << x;
        long long res = period / 2 * (num / period);
        if (num % period >= period / 2) {
            res += num % period - (period / 2 - 1);
        }
        return res;
    }

    long long check(int x,long long num){
        long long res = 0;
        int length = 60;
        for (int i = x; i <= length; i += x) {
            res += accumulatedBitPrice(i, num);
        }
        return res;
    }
    long long findMaximumNumber(long long k, int x) {
        long long l = 1,r = (k + 1) << x;
        while(l < r){
            long long mid = (l + r + 1) >> 1;
            if(check(x,mid) > k){
                r = mid - 1;
            }else {
                l = mid;
            }
        }
        return r;
    }
};