//https://leetcode.cn/problems/minimum-cost-to-make-two-binary-strings-equal/description/

class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n = s.size();

        int a = 0,b = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '0' && t[i] == '1'){
                a++;
            }else if(s[i] == '1' && t[i] == '0'){
                b++;
            }
        }
        if(a > b){
            swap(a,b);
        }
        //只翻转
        long long res1 = 1LL * (a + b) * flipCost;
        //先交换再翻转
        long long res2 = 1LL * a * swapCost + 1LL * (b - a) * flipCost;
        //先组间交换，再交换，翻转
        int avg = (a + b) / 2;
        long long res3 = 1LL *  (avg - a) * crossCost + 1LL * avg * swapCost + 1LL * (a + b ) % 2 * flipCost;
        return min(res1,min(res2,res3));
    }
};