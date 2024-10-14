//题目链接：https://leetcode.cn/problems/super-egg-drop/description/?envType=daily-question&envId=2024-10-14


/*
    官方题解：https://leetcode.cn/problems/super-egg-drop/solutions/197163/ji-dan-diao-luo-by-leetcode-solution-2/?envType=daily-question&envId=2024-10-14
*/

class Solution {
public:
    map<int,int> memo;
    int dp(int k,int n) {

            if(memo.find(n * 100 + k) == memo.end()){
                
                int ans = 0;
                if(n == 0){
                    ans = 0;
                }else if(k == 1){
                    ans = n;
                }else {
                    int lo = 1,hi = n;
                    while(lo + 1 < hi){
                        int x = (lo + hi) / 2;
                        int t1 = dp(k - 1,x - 1);
                        int t2 = dp(k,n - x);
                        if(t1 < t2){
                            lo = x;
                        }else if(t1 > t2){
                            hi = x;
                        }else {
                            lo = hi = x;
                        }
                    }
                    ans = 1 + min(max(dp(k - 1,lo - 1),dp(k,n - lo)),max(dp(k - 1,hi - 1),dp(k,n - hi)));
                }
                memo[100 * n + k ] = ans;
            }
            return memo[100 * n + k];
        }
        

    int superEggDrop(int k, int n) {
        return dp(k , n);
    }
};