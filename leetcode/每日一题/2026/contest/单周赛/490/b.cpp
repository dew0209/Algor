class Solution {
public:
    int get_n(int u){
        int res = 1;
        for(int i = 1;i <= u;i++){
            res *= i;
        }
        return res;
    }
    bool isDigitorialPermutation(int n) {
        int res = 0;
        vector<int> r(10,0);
        while(n){
            res += get_n(n % 10);
            r[n % 10]++;
            n /= 10;
        }
        while(res){
            r[res % 10]--;
            res /= 10;
        }
        for(int i = 0;i <= 9;i++){
            if(r[i] != 0){
                return false;
            }
        }
        return true;
        
    }
};