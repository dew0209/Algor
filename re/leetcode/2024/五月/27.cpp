// 题目链接：https://leetcode.cn/problems/find-missing-observations/description/?envType=daily-question&envId=2024-05-27

// 思路：暴力

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
       int m = rolls.size();
       int sum = (n + m) * mean;
       for(int i = 0;i < m;i++){
            sum -= rolls[i];
       }
        vector<int> res(n,0);
        int div = sum / n;
        int r = sum % n;
        vector<int> ans(0,0);
        if(div <= 0 || div > 6 || (div == 6 && r))return ans;
        cout << n << endl;
        for(int i = 0;i < n;i++){
            res[i] = div + (r > 0);
            if(r > 0)r--;
        }
       return res;
    }
};