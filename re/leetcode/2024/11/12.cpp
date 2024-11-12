//题目链接：https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/description/?envType=daily-question&envId=2024-11-12

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int a = 0;
        int b = 0;
        int j = 0;
        int res = 0;
        for(int i = 0;i < n;i++){ 
            if(s[i] == '1'){
                a++;
            }
            if(s[i] == '0'){
                b++;
            }
            while(j <= i && (a > k && b > k)){
                if(s[j] == '1')a--;
                if(s[j] == '0')b--;
                j++;
            }
            res = res + (i - j + 1);
        }
        return res;
    }
};