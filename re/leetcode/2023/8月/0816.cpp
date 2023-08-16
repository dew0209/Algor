题目链接：https://leetcode.cn/problems/find-the-losers-of-the-circular-game/

n  k
转球：从1开始
初始  1
1  1 + k

2 1 + 2k

3 1 + 3k

n 1 + nk

假设不存在，那么：1~n都转一次，那么下一次肯定会重复

所以肯定会有一个点被转到2次

1 ~ n 

第id个同学接到球了

id > n id - n

id = n + 1   id ---> 1

id = n + n   id ---> n

不好去控制下标

所以：将1~n全部换成0~n-1

因为 id % n 0~n-1

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> cnt(n,0);
        int tol = 0;
        for(int i = 0;!cnt[i % n];i += tol * k){
            cnt[i % n]++;
            tol++;
        }
        vector<int> res;
        for(int i = 0;i < n;i++){
            if(!cnt[i]){
                res.push_back(i + 1);
            }
        }
        return res;
    }
};