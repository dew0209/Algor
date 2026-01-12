//https://leetcode.cn/problems/count-residue-prefixes/


class Solution {
public:
    int residuePrefixes(string s) {
        map<char,int> cnt;

        int count = 0;
        int res = 0;

        for(int i = 0;i < s.size();i++){
            if(!cnt.count(s[i])){
                count++;
            }
            if(count == ((i + 1) % 3)){
                res++;
            }
            cnt[s[i]];
        }
        return res;
    }
};