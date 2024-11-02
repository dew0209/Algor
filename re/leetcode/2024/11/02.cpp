//题目链接：https://leetcode.cn/problems/number-of-bit-changes-to-make-two-integers-equal/description/?envType=daily-question&envId=2024-11-02


class Solution {
public:
    vector<int> getBit2(int n){

        vector<int> res;
        if(!n){
            res.push_back(n);
            return res;
        }
        while(n){
            res.push_back(n % 2);
            n /= 2;
        }
        return res;
    }
    int minChanges(int n, int k) {
        
        auto a = getBit2(n);
        auto b = getBit2(k);
        if(a.size() < b.size())return -1;
        int res = 0;

        for(int i = 0;i < a.size();i++){
            int x = a[i];
            int y = 0;
            if(i < b.size()){
                y = b[i];
            }
            if(x != y){
                if(x == 0){
                    res = -1;
                    break;
                }
                res ++;
            }
        }
        return res;
    }
};