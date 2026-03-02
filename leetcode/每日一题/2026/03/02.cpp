//https://leetcode.cn/problems/minimum-swaps-to-arrange-a-binary-grid/description/?envType=daily-question&envId=2026-03-02

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        //n - 1个 0 
        //n - 2个 0 
        //n - 3个 0
        //n - 4个 0
        int n = grid.size();
        vector<int> cnt(n,0);

        for(int i = 0;i < n;i++){
            //右侧有几个0
            for(int j = n - 1;j >= 0;j--){
                if (grid[i][j] == 1) {
                    cnt[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            int k = -1;
            for(int j = i;j < n;j++){
                if(cnt[j] <= i){
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if(~k){
                for(int j = k;j > i;j--){
                    swap(cnt[j],cnt[j - 1]);
                }
            }else {
                return -1;
            }
        }
        return ans;
    }
};