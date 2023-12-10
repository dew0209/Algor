题目链接：https://leetcode.cn/problems/climbing-stairs/description/?envType=daily-question&envId=2023-12-10


class Solution {
public:
    int climbStairs(int n) {
        int a = 1,b = 1,c = a;
        for(int i = 2;i <= n;i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};