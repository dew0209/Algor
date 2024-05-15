// 题目链接：https://leetcode.cn/problems/minimum-time-to-complete-all-tasks/description/?envType=daily-question&envId=2024-05-15

// 思路：贪心

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[&](const vector<int> &t1,const vector<int> &t2){
            return t1[1] < t2[1];
        });
        int res = 0;
        int n = tasks.size();
        vector<int> run(tasks[n - 1][1] + 1);
        for(int i = 0;i < n;i++){
            int st = tasks[i][0];
            int ed = tasks[i][1];
            int sum = tasks[i][2];
            sum -= accumulate(run.begin() + st,run.begin() + ed + 1,0);
            res += max(sum,0);
            for(int j = ed;j >= 0 && sum > 0;j--){
                if(run[j] == 0){
                    run[j] = 1;
                    sum--;
                }
            }
        }
        return res;
    }
};