题目链接：https://leetcode.cn/problems/move-pieces-to-obtain-a-string/

方法一：双指针

____L
R____ 
LR 
RL 

i 指向start
j 指向target

i和j不一定相等
s[i] t[j] '_' 可以
s[i] t[j] 'L' 可以 i >= j
s[i] t[j] 'R' 可以 i <= j
s[i] t[j] 不相等 直接结束返回一个false

注意：下划线不是代表可以替换，仅代表可以相邻移动

class Solution {
public:
    bool canChange(string s, string t) {
        int n = s.size();
        int i = 0,j = 0;
        while(i < n && j < n){
            while(i < n && s[i] == '_')i++;
            while(j < n && t[j] == '_')j++;
            if(i < n && j < n){
                if(s[i] != t[j])return false;
                if(s[i] == 'L'){
                    if(i < j)return false;
                }
                if(s[i] == 'R'){
                    if(i > j)return false;
                }
                i++;
                j++;
            }
        }
        while(i < n){
            if(s[i] != '_'){
                return false;
            }
            i++;
        }
        while(j < n){
            if(t[j] != '_'){
                return false;
            }
            j++;
        }
        return true;
    }
};