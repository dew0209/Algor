//https://leetcode.cn/problems/fancy-sequence/?envType=daily-question&envId=2026-03-15

const int MOD = 1e9 + 7;
class Fancy {
public:
    vector<int> res;
    long long add = 0;
    long long mul = 1;
    Fancy() {
        
    }

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }
    
    void append(int val) {
        res.push_back((val - add + MOD) * pow(mul, MOD - 2) % MOD);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        add = add * m % MOD;
        mul = mul * m % MOD;
    }
    
    int getIndex(int idx) {
        int n = res.size();
        if(idx >= n){
            return -1;
        }
        int x = res[idx];
        
        return (x * mul + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */