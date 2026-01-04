//https://leetcode.cn/problems/largest-even-number/

class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        int x = n;

        while(x - 1 >= 0 && (s[x - 1] - '0') % 2 == 1){
            x--;
        }
        
        return s.substr(0,x);
    }
};