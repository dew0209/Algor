long long arr[15] = {1,1,1,2,2,2,3,3,3,4,4,4,5,5,5};
class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        //该数字的长度
        int t = (to_string(n).size());

        long long r = 1;
        long long h = 9;
        long long len = 1;
        
        for(int i = 1;i <= t;i++){
            if(i >= 4){
                //有逗号
                if(i == t){
                    //最一轮
                    res += 1LL * arr[i - 4] * (n - r + 1);
                }else {
                    res += 1LL * arr[i - 4] * (h - r + 1);
                }
            }
            
            r = r * 10;
            h = h * 10 + 9;
            len++;
        }
        
        return res;
    }
};