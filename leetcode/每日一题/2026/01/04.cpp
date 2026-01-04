//https://leetcode.cn/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04

class Solution {
public:

    vector<int> get_prime(int u){
        vector<int> res(2,1);
       
        map<int,int> cnt;
        for(int i = 2;i <= u / i;i++){
            while(u % i == 0){
                cnt[i] ++;
                u /= i;
            }
        }
        if(u > 1){
            cnt[u] ++;
        }

        //计算
        for(auto [x,y] : cnt){
            res[0] *= y + 1;
            int t = 1;
            while(y --)t = t * x + 1;
            res[1] *= t;
        }
        
        return res;
    }

    int sumFourDivisors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxV = nums[n - 1];
        vector<int> cntA(n,0);
        vector<int> cntB(n,0);
        for(int i = 0;i < n;i++){
            auto res = get_prime(nums[i]);
            cntA[i] = res[0];
            cntB[i] = res[1];
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(cntA[i] == 4){
                ans += cntB[i];
            }
        }
        return ans;
    }
};