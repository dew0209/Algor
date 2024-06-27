//题目连接：https://leetcode.cn/problems/lexicographically-smallest-string-after-substring-operation/description/?envType=daily-question&envId=2024-06-27

//思路：分类

class Solution {
public:
    string smallestString(string s) {
        int idxA = -1;
        int idxB = -1;
        int n = s.size();
        for(int i = 0;i < n;i++){
            if(s[i] == 'a' && idxA == -1 && idxB != -1){
                idxA = i;
            }else if(s[i] != 'a' && idxB == -1 && idxA == -1){
                idxB = i;
            }
        }
        if(idxB == -1){
            s[n - 1] = 'z';
            return s;
        }
        if(idxA == -1){
            idxA = n;
        }
        for(int i = idxB;i < idxA;i++){
            s[i] = char(s[i] - 1);
        }
        return s;
    }
};