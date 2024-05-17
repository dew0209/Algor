// 题目链接：https://leetcode.cn/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-05-17

// 思路：双指针 + 排序

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> arr;
        int n = difficulty.size();
        for(int i = 0;i < n;i++){
            arr.push_back({difficulty[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
        sort(worker.begin(),worker.end());
        int res = 0;
        int idx = 0;
        int best = 0;
        for(int i = 0;i < worker.size();i++){
            while(idx < n && arr[idx].first <= worker[i]){
                best = max(best,arr[idx].second);
                idx++;
            }
            res = res + best;
        }
        return res;
    }
};