题目链接：https://leetcode.cn/problems/count-the-repetitions/description/?envType=daily-question&envId=2024-01-02

思路：循环节

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(n1 == 0)return 0;
        int s1_cnt = 0;
        int s2_cnt = 0;
        int index = 0;
        map<int,pair<int,int>> cell;
        pair<int,int> fi,se;
        while(true){
            ++s1_cnt;
            for(auto ch : s1){
                if(ch == s2[index]){
                    index++;
                    if(index == s2.size()){
                        ++s2_cnt;
                        index = 0;
                    }
                }
            }
            if(s1_cnt == n1){
                return s2_cnt / n2;
            }
            if(cell.count(index)){
                auto [x,y] = cell[index];
                fi = {x,y};
                se = {s1_cnt - x,s2_cnt - y};
                break;
            }else {
                cell[index] = {s1_cnt,s2_cnt};
            }
        }
        int ans = fi.second + (n1 - fi.first) / se.first * se.second;
        int rest = (n1 - fi.first) % se.first;
        for(int i = 0;i < rest;i++){
            for(auto ch : s1){
                if(ch == s2[index]){
                    index++;
                    if(index == s2.size()){
                        ans++;
                        index = 0;
                    }
                }
            }
        }
        return ans / n2;
    }
};