题目链接：https://leetcode.cn/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-13


思路：


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int a = 0;
        int b = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '1')a++;
            else b++;
        }
        string res = "";
        a--;
        while(a){
            res = res + "1";
            a--;
        }
        while(b){
            res = res + "0";
            b--;
        }
        return res + "1";
    }
};