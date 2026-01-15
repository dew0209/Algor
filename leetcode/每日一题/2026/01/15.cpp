//https://leetcode.cn/problems/maximize-area-of-square-hole-in-grid/description/?envType=daily-question&envId=2026-01-15


class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int h = 1;
        int hMax = 1;
        int w = 1;
        int wMax = 1;

        for(int i = 1;i < hBars.size();i++){
            if(hBars[i] == hBars[i - 1] + 1){
                h++;
            }else {
                h = 1;
            }
            hMax = max(h,hMax);
        }
        for(int i = 1;i < vBars.size();i++){
            if(vBars[i] == vBars[i - 1] + 1){
                w++;
            }else {
                w = 1;
            }
            wMax = max(w,wMax);
        }
        int r = min(hMax,wMax) + 1;
        return r * r;
    }
};