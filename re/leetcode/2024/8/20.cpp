//题目链接：https://leetcode.cn/problems/find-number-of-ways-to-reach-the-k-th-stair/?envType=daily-question&envId=2024-08-20

//思路：组合数学


class Solution {
public:
    int c[40][40];
    void init(){
        for(int i = 1;i < 31;i++){
            c[i][0] = c[i][i] = 1;
            for(int j = 1;j < i;j++){
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            } 
        }
    }
    int waysToReachStair(int k) {
        int ans = 0;
        init();
        for(int j = 0;j < 30;j++){
            int m = (1 << j) - k;
            if(m >= 0 && m <= j + 1){
                ans += c[j + 1][m];
            }
        }
        return ans;
    }
};