题目链接：https://leetcode.cn/problems/maximize-distance-to-closest-person/description/

方法一：双指针

[1,0,0,0,1,0,1]  2

[1,0,0,0]        3


..... 11111 ......   1   ...... 1  ....   1 .....


1    ......   1 

1  000 1
1 0000 1
1 00000 1
1 000000 1
sum:表示这一段1之间0的个数 (sum + 1) / 2


设头尾分别有 a b 个0
max(a,res) max(b,res)

res;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            int j = i;
            while(j < n && seats[j] == 1)j++;
            int sum = 0;
            while(j < n && seats[j] == 0)sum++,j++;
            if(sum){
                res = max(res,(sum + 1) / 2);
            }
            i = j;
        }
        int l = 0;
        while(l < n && seats[l] == 0)l++;
        int r = n - 1;
        while(r >= 0 && seats[r] == 0)r--;
        res = max(res,l);
        res = max(res,n - 1 - r);
        return res;
    }
};