//https://leetcode.cn/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14

string str[3] = {"a","b","c"};
class Solution {
public:
    string getHappyString(int n, int k) {
        vector<vector<int>> f(n + 1,vector<int>(3,0));
        f[1][0] = 1;
        f[1][1] = 1;
        f[1][2] = 1;
        for(int i = 2;i <= n;i++){
            f[i][1] += f[i - 1][2];
            f[i][1] += f[i - 1][0];

            f[i][0] += f[i - 1][1];
            f[i][0] += f[i - 1][2];

            f[i][2] += f[i - 1][0];
            f[i][2] += f[i - 1][1];
        }

        //确定字符串
        int len = n;
        string res = "";
        int last = -1;
        while(len){
            int sum = 0;            
            for(int i = 0;i < 3;i++){
                if(last != i){
                    sum += f[len][i];
                    if(sum >= k){
                        res += str[i];
                        k -= sum;
                        k += f[len][i];
                        last = i;
                        break;
                    }
                }
            }
            len--;
        }
        return res;
    }
};