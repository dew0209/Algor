//https://leetcode.cn/problems/count-the-number-of-powerful-integers/?envType=daily-question&envId=2025-04-10


class Solution {
    public:
        //位数为i，最高位为j情况
        long long f[20][20];
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {        
            int n = s.size();
            //初始化开始
            for(int i = 0;i < n;i++){
                f[n - i][s[i] - '0'] = 1;
            }
            for(int i = n + 1;i < 20;i++){
                for(int j = 0;j <= 9;j++){
                    if(j <= limit){
                        for(int k = 0;k <= 9;k++){
                            f[i][j] += f[i - 1][k];
                        }
                    }
                }
            }
            //初始化结束
    
            //计算结果
            return getRes(finish,s,limit) - getRes(start - 1,s,limit);
        }
    
        long long getRes(long long u,string s,int limit){
            vector<int> num = get_num(u);
            long long res = 0;
            int n = num.size();
            if(n < s.size())return 0;
            int sIdx = 0;
            //位数为n的情况（也就是不含前缀0的情况）
            for(int i = n - 1;i >= 0;i--){
                int x = num[i];
                for(int j = (i == n - 1);j < x && j <= limit;j++){
                    //i + 1 长度 且 最高位为j的情况
                    res += f[i + 1][j];
                }
                if(x > limit)break;
                if(i <= s.size() - 1){
                    if(x != (s[sIdx++] - '0')){
                        break;
                    }
                }
                if(!i)res++;
            }
            //位数不为n的情况（也就是含前缀0的情况）
            for(int i = s.size();i < n;i++){
                for(int j = 1;j <= 9;j++){
                    res += f[i][j];
                }
            }
            return res;
        }
    
        vector<int> get_num(long long num){
            vector<int> res;
            while(num){
                res.push_back(num % 10);
                num /= 10;
            }
            return res;
        }
    };