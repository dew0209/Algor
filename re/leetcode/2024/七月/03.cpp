//题目连接：https://leetcode.cn/problems/harshad-number/description/?envType=daily-question&envId=2024-07-03


//遍历

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int n = 0;
        int q = x;
        while(x){
            n += x % 10;
            x /= 10;
        }
        if(q && n && q % n == 0){
            return n;
        }
        return -1;
    }
};