//https://leetcode.cn/problems/rotated-digits/?envType=daily-question&envId=2026-05-02

class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            string num = to_string(i);
            bool valid = true, diff = false;
            for (char ch: num) {
                if (check[ch - '0'] == -1) {
                    valid = false;
                }
                else if (check[ch - '0'] == 1) {
                    diff = true;
                }
            }
            if (valid && diff) {
                ++ans;
            }
        }
        return ans;
    }

private:
    static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
};