//https://leetcode.cn/problems/count-the-number-of-computer-unlocking-permutations/description/?envType=daily-question&envId=2025-12-10

class Solution {
public:
    long long MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        bool ok = false;
        for(int i = 1;i < n;i++){
            if(complexity[i] <= complexity[0]){
                ok = true;
                break;
            }
        }

        if(ok)return 0;

        long long res = 1;


        for(int i = 1;i <= n - 1;i++){
            res = i * res % MOD;
        }
        return (int)res;
    }
};