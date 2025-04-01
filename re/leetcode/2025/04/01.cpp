//反向思维

const int N = 100010;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> f(n + 10);
        for(int i = n - 1;i >= 0;i--){
            f[i] = max(f[i + 1],((i + questions[i][1] + 1) >= n ? 0 : f[i + questions[i][1] + 1]) + (long long)questions[i][0]) ;
        }
        return f[0];
    }
};