//https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=daily-question&envId=2026-03-29


class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i = 0;i < 4;i++){
            if(s1[i] != s2[i]){
                if(i + 2 < 4){
                    
                    if(s1[i + 2] == s2[i]){
                        swap(s1[i],s1[i + 2]);
                    }else {
                        return false;
                    }

                }else {
                    return false;
                }
            }
        }
        return true;
    }
};