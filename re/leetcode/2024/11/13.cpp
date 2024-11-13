//题目链接：https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-ii/description/?envType=daily-question&envId=2024-11-13



typedef long long LL;
class Solution {
public:
    LL sum[100010];
    int cnt[2];
    int right[100010];
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        for(int i = 0;i <= n;i++){
            right[i] = n;
        }
        for(int i = 0,j = 0;i < n;i++){
            cnt[s[i] - '0']++;

            while(cnt[0] > k && cnt[1] > k){
                cnt[s[j] - '0']--;
                right[j] = i;
                j++;
            }
            sum[i + 1] = sum[i] + (i - j + 1);
        }
        
        int m = queries.size();
        vector<LL> res;
        for(int i = 0;i < m;i++){
            int l = queries[i][0],r = queries[i][1];
            LL ed = min(right[l],r + 1);
            LL calc = (LL)(ed - l + 1) * (ed - l) / 2;
            calc = calc + sum[r + 1] - sum[ed];
            res.push_back(calc);
        }
        return res;
    }
};