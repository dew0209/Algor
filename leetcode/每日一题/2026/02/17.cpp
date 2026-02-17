//https://leetcode.cn/problems/binary-watch/description/?envType=daily-question&envId=2026-02-17


class Solution {
public:
    int lowbit(int u){
        int res = 0;
        for(int i = u;i;i -= i & -i){
            res++;
        }
        return res;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int i = 0;i < 12;i++){
            for(int j = 0;j < 60;j++){
                if(lowbit(i) + lowbit(j) == turnedOn){
                    string x = to_string(i) + ":" + (j >= 10 ? to_string(j) : to_string(0) + to_string(j));
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};