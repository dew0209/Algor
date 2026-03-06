//https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06


class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '1'){
                int j = i;
                while(j < n && s[j] == s[i])j++;
                i = j - 1;
                ans++;
            }
        }
        return ans  <= 1;
    }
};