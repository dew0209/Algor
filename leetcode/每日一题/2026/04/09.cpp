//https://leetcode.cn/problems/xor-after-range-multiplication-queries-ii/description/?envType=daily-question&envId=2026-04-09

const int MOD = 1e9 + 7;

class Solution {
public:
    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int B = sqrt(m);
        vector<vector<int>> diff(B);
        for(auto& q : queries){
            int l = q[0],r = q[1],k = q[2],v = q[3];
            if(k >= B){
                for(int i = l;i <= r;i += k){
                    nums[i] = 1LL * nums[i] * v % MOD;
                }
            }else {
                if(diff[k].empty()){
                    diff[k].resize(n + k,1);
                }
                diff[k][l] = 1LL * diff[k][l] * v % MOD;
                r = r - (r - l) % k + k;
                diff[k][r] = diff[k][r] * pow(v,MOD - 2) % MOD;
            }

        }
        for(int k = 1;k < B;k++){
            auto& d = diff[k];
            if(d.empty()){
                continue;
            }
            for(int st = 0;st < k;st++){
                long long mul_d = 1;
                for(int i = st;i < n;i += k){
                    mul_d = mul_d * 1LL * d[i] % MOD;
                    nums[i] = nums[i] * 1LL * mul_d % MOD;
                }
            }
        }
        int res = 0;
        for(int i = 0;i < n;i++){
            res = res ^ nums[i];
        }
        return res;
    }
};