// 题目链接：https://leetcode.cn/problems/watering-plants/description/?envType=daily-question&envId=2024-05-08
// 思路：模拟


class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int maxV = capacity;
        int n = plants.size();
        int st = -1;
        int res = 0;
        for(int i = 0;i < n;i++){
            if(capacity < plants[i]){
                capacity = maxV;
                res += ((i - 1) - st) * 2;
            }
            capacity -= plants[i];
            res++;
        }
        return res;
    }
};