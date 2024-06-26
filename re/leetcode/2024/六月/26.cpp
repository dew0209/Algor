//题目连接：https://leetcode.cn/problems/special-permutations/description/?envType=daily-question&envId=2024-06-26

//思路：dp

const int MOD = 1e9+7;
class Solution {
public:
    int f[20010][20];
    int specialPerm(vector<int>& nums) {
        int n  = nums.size();

        for(int i = 0;i < n;i++){
            f[1 << i][i] = 1;
        }

        for(int state = 1;state < (1 << n);state++){
            for(int i = 0;i < n;i++){

                if(!(state >> i & 1)){
                    continue;
                }

                for(int j = 0;j < n;j++){
                    if(i == j || !(state >> j & 1)){
                        continue;
                    }

                    if(nums[i] % nums[j] != 0 && nums[j] % nums[i] != 0){
                        continue;
                    }

                    f[state][i] = (f[state][i] + f[state ^ (1 << i)][j]) % MOD;
                }
            }
        }
        int res = 0;
        for(int i = 0;i < n;i++){
            res = (res + f[(1 << n) - 1][i]) % MOD;
        }
        return res;
    }
};