//https://leetcode.cn/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/?envType=daily-question&envId=2026-04-04

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ax = startPos[0];
        int bx = homePos[0];
        int res = 0;
        if(ax != bx){
            res += rowCosts[bx];
        }
        if(ax > bx){
            swap(ax,bx);
        }
        
        for(int i = ax + 1;i < bx;i++){
            res += rowCosts[i];
        }
        int ay = startPos[1];
        int by = homePos[1];
        if(ay != by){
            res += colCosts[by];
        }
        if(ay > by){
            swap(ay,by);
        }
        for(int i = ay + 1;i < by;i++){
            res += colCosts[i];
        }
        return res;
    }
};