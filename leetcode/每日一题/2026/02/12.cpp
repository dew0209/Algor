//https://leetcode.cn/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            vector<int> cnt(26,0);
            for(int j = i;j < n;j++){
                cnt[s[j] - 'a']++;
                int te = 0;
                bool ok = true;
                for(auto& c : cnt){
                    if(c > 0){
                        if(te == 0){
                            te = c;
                        }else if(te != c){
                            ok = false;
                            break;
                        }
                    }
                }
                if(ok){
                    res = max(res,j - i + 1);
                }
            }
        }
        return res;
    }
};