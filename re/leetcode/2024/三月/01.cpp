题目链接：https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/description/?envType=daily-question&envId=2024-03-01

思路：dp

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 10,0);
        f[0] = 1;
        for(int i = 1;i <= n;i++){
            if(i >= 2){
                f[i] = f[i - 2] && val2(nums[i - 2],nums[i - 1]);
            }
            if(i >= 3){
                f[i] = f[i] || (f[i - 3] && val3(nums[i - 3],nums[i - 2],nums[i - 1]));
            }
        }
        return f[n];
    }
    int val2(int a,int b){
        return a == b;
    }
    int val3(int a,int b,int c){
        int da = b - a;
        int db = c - b;
        int f1 = (a == b ) && (b == c);
        int f2 = (da == 1) && (db == da);
        return f1 || f2;
    }
};