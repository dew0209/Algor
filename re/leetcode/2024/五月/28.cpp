// 题目链接：https://leetcode.cn/problems/find-the-peaks/description/?envType=daily-question&envId=2024-05-28

// 思路：暴力

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> res;
        int n = mountain.size();

        for(int i = 1;i < n - 1;i++){
            if(mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]){
                res.push_back(i);
            }
        }
        return res;
    }
};