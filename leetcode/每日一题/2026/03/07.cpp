//https://leetcode.cn/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/?envType=daily-question&envId=2026-03-07

class Solution {
public:

    int minFlips(string s) {
        int n = s.size();
        int ans = n,cnt = 0;

        for(int i = 0;i < 2 * n - 1;i++){

            if((s[i % n] % 2 != i % 2)){
                cnt++;
            }
            int left = i - n + 1;

            if(left < 0)continue;

            ans = min(ans,min(n - cnt,cnt));

            if((s[left % n] % 2 != left % 2)){
                cnt--;
            }
        }
        return ans;
    }
};