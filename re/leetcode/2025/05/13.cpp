//https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13

const int MOD = 1e9 + 7;
class Solution {
public:

    vector<vector<int>> mul(vector<vector<int>> a,vector<vector<int>> b){
        vector<vector<int>> res(26,vector<int>(26,0));;
        
        for(int i = 0;i < 26;i++){
            for(int k = 0;k < 26;k++){
                if(a[i][k] == 0)continue;
                for(int j = 0;j < 26;j++){
                    res[i][j] = (res[i][j] + (long long)a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    vector<vector<int>> mul(vector<vector<int>> a,int b){
        vector<vector<int>> res(26,vector<int>(26,0));;
        for(int i = 0;i < 26;i++){
            res[i][i] = 1;
        }
        while(b){
            if(b & 1){
                res = mul(res,a);
            }
            a = mul(a,a);
            b >>= 1;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t) {
        //矩阵
        vector<vector<int>> m(26,vector<int>(26,0));

        vector<int> nums(26,1);

        nums[25] = 2;

        //转换规则基础矩阵构造
        for(int i = 0;i < 26;i++){
            for(int j = i + 1;j <= i + nums[i];j++){
                m[i][j % 26] = 1;
            }
        }

        for(int i = 0;i < 26;i++){
            for(int j = 0;j < 26;j++){
                cout << m[i][j] << ' ';
            }
            cout << endl;
        }

        auto mt = mul(m,t);

        vector<int> cnt(26,0);

        for(int i = 0;i < s.size();i++){
            cnt[s[i] - 'a']++;
        }

        long long res = 0;

        for(int i = 0;i < 26;i++){
            res = res + reduce(mt[i].begin(), mt[i].end(), 0LL) * cnt[i] % MOD;
        }
        return res % MOD;
    }
};