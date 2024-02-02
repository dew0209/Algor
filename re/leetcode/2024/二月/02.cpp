题目链接：https://leetcode.cn/problems/stone-game-vi/description/?envType=daily-question&envId=2024-02-02


思路：贪心

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> arr(n);
        iota(arr.begin(),arr.end(),0);
        sort(arr.begin(),arr.end(),[&aliceValues,&bobValues](const int aValue,const int bValue){
            return aliceValues[aValue] + bobValues[aValue] > aliceValues[bValue] + bobValues[bValue];
        });
        int sum = 0;
        for(int i = 0;i < n;i++){
            if(i&1){
                sum -= bobValues[arr[i]];
            }else {
                sum += aliceValues[arr[i]];
            }
        }
        
        return sum == 0 ? 0 : (sum > 0 ? 1 : -1);
    }
};