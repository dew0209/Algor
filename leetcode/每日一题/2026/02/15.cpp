//https://leetcode.cn/problems/add-binary/description/?envType=daily-question&envId=2026-02-15

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();

        int t = 0;

        string res;

        for(int i = 0;i < n || i < m;i++){
            if(n - 1 - i >= 0){
                t += (a[n - 1 - i] - '0');
            }
            if(m - 1 - i >= 0){
                t += (b[m - 1 - i] - '0');
            }

            res += to_string(t % 2);
            t /= 2;
        }
        if(t){
            res += to_string(t);
        }
        reverse(res.begin(),res.end());
        return res;

    }
};