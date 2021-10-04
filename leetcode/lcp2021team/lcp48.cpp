/*
 * 无限棋局，三步之内，判断谁赢了，或者平局
 * 开始统计： 4连的位置，如果一开始黑子有四连的位置，则直接获胜
 *          如果黑子没有四连的位置，白子有四连的位置，且四连的位置 >= 2，则白子获胜，因为黑子在第一手的情况下，无法阻止两个位置
 *          如果黑子没有四连的位置，白子四连的位置为1，则第一手黑子直接卡住白子，然后继续枚举四连的位置，如果黑子四连的位置>=2则黑子获胜
 *          如果黑子没有四连的位置，白子没有四连的位置，则黑子寻找三连的位置，如果三连的位置>=2，则黑子获胜
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

typedef pair<int,int> PII;

const int N = 1010;

//八连通
int dx[8] = {0, -1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1, 0, 1,1,1,0,-1};

//有要求
//int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
//int dy[8] = {-1, 0,   1, -1, 1, -1, 0, 1};


class Solution {
public:
    string gobang(vector<vector<int>>& pp) {
        map<PII,int> mp;
        for(auto& x : pp){
            mp[PII(x[0],x[1])] = x[2];
        }
        set<PII> kp[2];
        for (auto &x : pp) {
            //位置和颜色
            int u = x[0], v = x[1], w = x[2];
            for (int d = 0; d < 8; d++) {
                int same_cnt = 0, empty_cnt = 0, empty_pos = 0;
                for (int j = 1; j <= 4; j++) {
                    auto maki = mp.find(PII(u + dx[d] * j, v + dy[d] * j));
                    if (maki == mp.end()) empty_cnt++, empty_pos = j;//空位
                    else if (maki->second == w) same_cnt++;//同样的颜色
                }
                if (same_cnt == 3 && empty_cnt == 1) {
                    kp[w].insert(PII(u + dx[d] * empty_pos, v + dy[d] * empty_pos));
                }
            }
        }
        //黑子有位置可以下
        if(!kp[0].empty())return "Black";
        if(kp[1].size() > 1)return "White";
        if(kp[1].size() == 1){
            auto nico = kp[1].begin();
            pp.push_back(vector<int>({nico->first, nico->second, 0}));
            mp[*nico] = 0;
            kp[0].clear(), kp[1].clear();
            for (auto &x : pp) {
                int u = x[0], v = x[1], w = x[2];
                for (int d = 0; d < 8; d++) {
                    int same_cnt = 0, empty_cnt = 0, empty_pos = 0;
                    for (int j = 1; j <= 4; j++) {
                        auto maki = mp.find(PII(u + dx[d] * j, v + dy[d] * j));
                        if (maki == mp.end()) empty_cnt++, empty_pos = j;
                        else if (maki->second == w) same_cnt++;
                    }
                    if (same_cnt == 3 && empty_cnt == 1) {
                        kp[w].insert(PII(u + dx[d] * empty_pos, v + dy[d] * empty_pos));
                    }
                }
            }
            if (kp[0].size() > 1) return "Black";
            else return "None";
        } else{
            set<PII> potential_pos;
            for(auto& x : pp){
                int u = x[0],v = x[1],w = x[2];
                if(w == 0){
                    for(int d = 0;d < 8;d++){
                        for(int j = 1;j <= 2;j++){
                            potential_pos.insert(PII(u + dx[d] * j,v + dy[d] * j));
                        }
                    }
                }
            }
            for(auto& x : pp){
                potential_pos.erase(PII(x[0],x[1]));
            }
            for(auto& first_step : potential_pos){
                kp[0].clear();
                int u = first_step.first,v = first_step.second,w = 0;
                for(int d = 0;d < 8;d++){
                    for(int f = -4;f <= 0;f++){
                        int same_cnt = 0,empty_cnt = 0,empty_pos = 0;
                        for(int j = 0;j <= 4;j++)if(f + j != 0){
                                auto maki = mp.find(PII(u + dx[d] * (f + j),v + dy[d] * (f + j)));
                                if(maki == mp.end())empty_cnt++,empty_pos = f + j;
                                else if(maki -> second == w)same_cnt++;
                            }
                        if(same_cnt == 3 && empty_cnt == 1)
                            kp[0].insert(PII(u + dx[d] * empty_pos,v + dy[d] * empty_pos));
                    }
                }
                if(kp[0].size() > 1)return "Black";
            }
            return "None";
        }
    }
};