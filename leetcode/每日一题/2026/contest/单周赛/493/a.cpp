class Solution {
public:
    int countCommas(int n) {
        int res = 0;
        for(int i = 1000;i <= n;i++){
            int t = (to_string(i).size());
            if(t <= 6){
                res += 1;
            }else {
                res += 2;
            }
        }
        return res;
    }
};