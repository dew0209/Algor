//a b c d e f g h i j k l m n o p q r s t u v w x y z
class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.size();
        vector<int> cnta(26,0);
        vector<int> cntb(10,0);
        for(int i = 0;i < n;i++){
            char c = s[i];
            if(c >= 'a' && c <= 'z'){
                cnta[c - 'a']++;
            }else {
                cntb[c - '0']++;
            }
        }
        int ans = 0;
        for(int i = 0;i < 13;i++){
            if(cnta[i] != 0 || cnta[25 - i] != 0){
                int currCh = i;
                int swapCh = 25 - i;
                ans += abs(cnta[i] - cnta[25 - i]);
            }
        }

        for(int i = 0;i < 5;i++){
            if(cntb[i] != 0 || cntb[9 - i] != 0){
                int currCh = i;
                int swapCh = 9 - i;
                ans += abs(cntb[i] - cntb[9 - i]);
            }
        }
        
        return ans;
    }
};