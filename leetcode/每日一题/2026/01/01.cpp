//https://leetcode.cn/problems/plus-one/?envType=daily-question&envId=2026-01-01

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int n = digits.size();
        int t = 1;
        for(int i = n - 1;i >= 0;i--){
            t += digits[i];
            res.push_back(t % 10);
            t /= 10;
        }
        if(t){
            res.push_back(t);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};  