题目链接：https://leetcode.cn/problems/max-pair-sum-in-an-array/description/

方法一：暴力

直接记录每个数位上出现的数的个数和最大的两个即可

class Solution {
public:
    //找出每个位上的最大数字是多少
    int get_max(int u){
        int res = 0;
        while(u){
            res = max(res,u % 10);
            u /= 10;
        }
        return res;
    }

    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        //记录每个数位出现的次数
        vector<int> cnt(10,0);
        //记录对应数组上出现的最大的数
        vector<int> tol(10,0);
        //排序
        sort(nums.begin(),nums.end());
        for(int i = n - 1;i >= 0;i--){
            int v = get_max(nums[i]);
            if(cnt[v] == 0){
                //记录该数位上最大的数
                tol[v] = nums[i];
                //该数位次数+1
                cnt[v]++;
            }else if(cnt[v] == 1){
                //最大的已经被记录过了，接下来直接更新答案就行了
                res = max(res,tol[v] + nums[i]);
                //该数位最大两个数已经被找出来了，接下的数就可以直接忽略了
                cnt[v]++;
            }
        }
        return res;
    }
};

方法二：针对方法一的优化

class Solution {
public:

    int get_max(int u){
        int res = 0;
        while(u){
            res = max(res,u % 10);
            u /= 10;
        }
        return res;
    }

    int maxSum(vector<int>& nums) {
        vector<int> cnt(10,-0x3f3f3f3f);
        int res = -1;
        for(int i = 0;i < nums.size();i++){
            int v = get_max(nums[i]);
            //如果只出现一次，结果还是-1，因为cnt数组被初始化为-0x3f3f3f3f
            res = max(res,cnt[v] + nums[i]);
            cnt[v] = max(cnt[v],nums[i]);
        }
        return res;
    }
};