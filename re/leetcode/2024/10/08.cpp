//题目链接：https://leetcode.cn/problems/destination-city/?envType=daily-question&envId=2024-10-08

//思路：离散化 出度入度

class Solution {
public:
    map<string,int> mp;
    int s1[200];
    int s2[200];
    int id = 1;

    int get(string pa){
        if(mp[pa] != 0){
            return mp[pa];
        }
        mp[pa] = id;
        id++;
        return mp[pa];
    }

    string destCity(vector<vector<string>>& paths) {
        //离散化
        for(auto& pa : paths){
            int a = get(pa[0]);
            int b = get(pa[1]);
            s1[a]++;
            s2[b]++;
        }
        for(auto& pa : paths){
            int b = get(pa[1]);
            if(s1[b] == 0 && s2[b] != 0){
                return pa[1];
            }

        }
        return "";
    }
};