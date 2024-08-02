//https://leetcode.cn/problems/uOAnQW/description/?envType=daily-question&envId=2024-08-01

class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(),cards.end());
        int n = cards.size();
        int res = 0;
        int ans = 0;
        int a = 0;
        int b = 0;
        for(int i = n - cnt;i < n;i++){
            res += cards[i];
            if(cards[i] % 2 == 1 && !a){
                a = cards[i];
            }
            if(cards[i] % 2 == 0 && !b){
                b = cards[i];
            }
        }
        if(res % 2 == 0){
            ans = res;
        }else {
            //最大的偶数
            int c = 0;
            //最大的奇数
            int d = 0;
            for(int i = n - cnt - 1;i >= 0;i--){
                if(cards[i] % 2 == 0 && !c){
                    c = cards[i];
                }
                if(cards[i] % 2 == 1&& !d){
                    d = cards[i];
                }
            }
            
            if(c != 0 && a != 0){
                ans = max(ans,res + c - a);
            }
            if(d != 0 && b != 0){
                ans = max(ans,res + d - b);
            }
        }
        return ans;
    }
};