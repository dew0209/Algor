//https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/?envType=daily-question&envId=2026-03-30


class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<char,int> cnt1;
        map<char,int> cnt2;
        int n = s1.size();
        for(int i = 0;i < n;i++){
            if(i % 2 == 0){
                cnt1[s1[i]]++;
            }else {
                cnt2[s1[i]]++;
            }
        }
        for(int i = 0;i < n;i++){
            char ch = s2[i];
            if(i % 2 == 0){
                if(!cnt1.contains(ch)){
                    return false;
                }
                cnt1[s2[i]]--;
            }else {
                if(!cnt2.contains(ch)){
                    return false;
                }
                cnt2[s2[i]]--;
            }
        }
        for(auto& [x,y] : cnt1){
            if(y != 0){
                return false;
            }
        }
        for(auto& [x,y] : cnt2){
            if(y != 0){
                return false;
            }
        }
        return true;
    }
};