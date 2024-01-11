题目链接：https://leetcode.cn/problems/minimum-additions-to-make-valid-string/description/?envType=daily-question&envId=2024-01-11

思路：推理
class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int res = 1;
        for(int i = 1;i < n;i++){
            if(word[i] <= word[i - 1]){
                res++;
            }
        }
        return res * 3 - n;
    }
};

思路：dp
class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        vector<int> f(n + 10,0);
        for(int i = 1;i <= n;i++){
            f[i] = f[i - 1] + 2;
            if(i > 1 && word[i - 1] > word[i - 2]){
                f[i] = f[i - 1] - 1; 
            }
        }
        return f[n];
    }
};