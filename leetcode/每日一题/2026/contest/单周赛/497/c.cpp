class Solution {
public:
    int longestBalanced(string s) {
        int total0 = ranges::count(s, '0');
        int total1 = s.size() - total0;
        int n = s.size();
        vector<int> sum(n + 1,0);
        for(int i = 1;i <= n;i++){
            sum[i] = sum[i - 1] + (s[i - 1] == '0' ? -1 : 1);
        }
        map<int,vector<int>> cnt;
        cnt[0].push_back(0);
        int ans = 0;

        for(int i = 1;i <= n;i++){
            int x = sum[i];
            if((int)(cnt[x].size()) < 2){
                cnt[x].push_back(i);
            }
            //不交换
            ans = max(ans,i - cnt[x][0]);
            //内1 外0
            auto it = cnt.find(x - 2);
            if(it != cnt.end()){
                auto& p = it->second;
                if((i - p[0] - 2) / 2 < total0){
                    ans = max(ans,i - p[0]);
                }else if(p.size() > 1){
                    ans = max(ans,i - p[1]);
                }
            }

            //内0 外1
            it = cnt.find(x + 2);
            if (it != cnt.end()) {
                auto& p = it->second;
                if ((i - p[0] - 2) / 2 < total1) {
                    ans = max(ans, i - p[0]);
                } else if (p.size() > 1) {
                    ans = max(ans, i - p[1]);
                }
            }

        }
        return ans;
    }
};