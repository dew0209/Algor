//https://leetcode.cn/problems/two-furthest-houses-with-different-colors/description/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(colors[i] != colors[j]){
                    res = max(res,abs(i - j));
                }
            }
        }
        return res;
    }
};