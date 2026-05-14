//https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/description/?envType=daily-question&envId=2026-05-12


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](auto a,auto b){return (a[1] - a[0]) < (b[1] - b[0]);});
        int ans = 0;
        for(auto& task : tasks){
            int a = task[0],minv = task[1];
            ans = max(ans + a,minv);
        }
        return ans;
    }
};



class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](auto a,auto b){return (a[1] - a[0]) > (b[1] - b[0]);});
        int ans = 0;
        int s = 0;
        for(auto& task : tasks){
            int a = task[0],minv = task[1];
            ans = max(ans,s + minv);
            s += a;
        }
        return ans;
    }
};