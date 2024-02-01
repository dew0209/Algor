题目链接：https://leetcode.cn/problems/5TxKeK/description/?envType=daily-question&envId=2024-02-01

思路：中位数，对顶栈（一大一小的栈）

class Solution {
public:
    vector<int> numsGame(vector<int>& nums) {
        priority_queue<int> lower;
        priority_queue<int,vector<int>,greater<>> upper;
        int n = nums.size();
        vector<int> res(n);
        long long sumLower = 0;
        long long sumUpper = 0;
        for(int i = 0;i < n;i++){
            int x = nums[i] - i;
            if(lower.empty() || lower.top() >= x){
                lower.push(x);
                sumLower += x;
                if(lower.size() > upper.size() + 1){
                    x = lower.top();
                    upper.push(x);
                    sumUpper += x;

                    sumLower -= x;
                    lower.pop();
                }
            }else {
                upper.push(x);
                sumUpper += x;
                if(upper.size() > lower.size()){
                    x = upper.top();
                    sumUpper -= x;
                    upper.pop();

                    lower.push(x);
                    sumLower += x;
                }
            }
            if((i + 1) % 2 == 0){
                res[i] = (sumUpper - sumLower) % 1000000007;
            }else {
                res[i] = (sumUpper - sumLower + lower.top()) % 1000000007;  
            }
        }
        return res;
    }
};