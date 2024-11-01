//题目链接：https://leetcode.cn/problems/maximum-energy-boost-from-two-drinks/description/?envType=daily-question&envId=2024-11-01


const int N = 100010;

long long f[N][3];

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        for(int i = 1;i <= n;i++){
            //f[i][0]:什么也不干
            f[i][0] = max(f[i - 1][1],f[i - 1][2]);
            f[i][1] = max(f[i - 1][1],f[i - 1][0]) + (long long)energyDrinkA[i - 1];
            f[i][2] = max(f[i - 1][2],f[i - 1][0]) + (long long)energyDrinkB[i - 1];
        }
        return max(f[n][1],f[n][2]);
    }
};