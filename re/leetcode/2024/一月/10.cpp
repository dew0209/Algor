https://leetcode.cn/problems/minimum-string-length-after-removing-substrings/description/?envType=daily-question&envId=2024-01-10

思路：栈

class Solution {
public:
    int st[110];
    int minLength(string s) {
        
        int top = -1;
        for(char c : s){
            st[++top] = c;
            if(top >= 1){
                if(st[top] == 'D' && st[top - 1] == 'C'){
                    top -= 2;
                }else if(st[top] == 'B' && st[top - 1] == 'A'){
                    top -= 2;
                }
            }
        }
        return top + 1;
    }
};