题目链接：https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/description/?envType=daily-question&envId=2024-01-01

思路：模拟

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = -1,money = 0;
        int vans = 0,vmoney = 0;
        int people = 0;
        for(int i = 0;i < customers.size() || people > 0;i++){
            if(i < customers.size()){
                people += customers[i];
            }
            int nowPer = min(people,4);
            people -= nowPer;
            vmoney += nowPer * boardingCost - runningCost;
            if(vmoney > money){
                money = vmoney;
                ans = i + 1;
            }
        }
        return ans;
    }
};