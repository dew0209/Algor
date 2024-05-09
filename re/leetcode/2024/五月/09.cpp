// 题目链接：https://leetcode.cn/problems/watering-plants-ii/description/?envType=daily-question&envId=2024-05-09

// 思路：模拟

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int a = capacityA;
        int b = capacityB;
        int n = plants.size();
        int l = 0,r = n - 1;
        int res = 0;
        while(l <= r){
            if(l < r || (l == r && a >= b)){
                if(a < plants[l]){
                    a = capacityA;
                    res++;
                }
                a -= plants[l];
                plants[l] = 0;
            }
            if(b < plants[r]){
                b = capacityB;
                res++;
            }
            b -= plants[r];
            plants[r] = 0; 
            l++;
            r--;
        }
        return res;
    }
};