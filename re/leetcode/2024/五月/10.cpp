// 题目链接：https://leetcode.cn/problems/count-tested-devices-after-test-operations/description/?envType=daily-question&envId=2024-05-10

// 思路：暴力

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int res = 0;
        int cnt = 0;
        for(int i = 0;i < n;i++){
            batteryPercentages[i] = max(batteryPercentages[i] - cnt,0);
            if(batteryPercentages[i] > 0){
                res++;
                cnt++;
            }
        }
        return res;
    }
};