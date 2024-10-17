//题目链接：https://leetcode.cn/problems/count-the-number-of-inversions/description/?envType=daily-question&envId=2024-10-17

class Solution {
public:

    unordered_map<int,int> reqMap;

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
       const int N = 1e9 + 7;
       int maxCnt = 0;
       reqMap[0] = 0;
       for(auto& req : requirements){
            reqMap[req[0]] = req[1];
            maxCnt = max(maxCnt,req[1]);
       }
       if(reqMap[0]){
         return 0;
       }
        vector<vector<int>> dp(n,vector<int>(maxCnt + 1,-1));
        function<int(int,int)> dfs = [&](int end,int cnt) -> int {
            if(end == 0){
                return 1;
            }
            if(dp[end][cnt] != -1){
                return dp[end][cnt];
            }
            if(reqMap.count(end - 1)){
                int r = reqMap[end - 1];
                if(r <= cnt && cnt <= end + r){
                    return dp[end][cnt] = dfs(end - 1,r);
                }else {
                    return dp[end][cnt] = 0;
                }
            }else {
                int sm = 0;
                for(int i = 0;i <= min(end,cnt);i++){
                    sm = (sm + dfs(end - 1,cnt - i)) % N;
                }
                return dp[end][cnt] = sm;
            }
        };
        return dfs(n - 1,reqMap[n - 1]);
    }
};