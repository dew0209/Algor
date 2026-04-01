//https://leetcode.cn/problems/robot-collisions/description/?envType=daily-question&envId=2026-04-01

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n,0);
        for(int i = 0;i < n;i++){
            idx[i] = i;
        }
        sort(idx.begin(),idx.end(),[&](int a,int b){
            return positions[a] < positions[b];
        });
        vector<tuple<int,int,char>> alive;
        for(auto i : idx){
            int cur = i,curHp = healths[i];
            char curDir = directions[i];

            while(alive.size()){
                auto [preidx,preHp,preDir] = alive.back();
                if(preDir == 'R' && curDir == 'L'){
                    alive.pop_back();
                    if(preHp > curHp){
                        cur = preidx;
                        curHp = preHp - 1;
                        curDir = preDir;
                    }else if(preHp < curHp){
                        curHp -= 1;
                    }else {
                        cur = -1;
                        break;
                    }

                }else {
                    break;
                }
            }
            if(cur != -1){
                alive.push_back({cur,curHp,curDir});
            }

        }
        sort(alive.begin(),alive.end());
        vector<int> ans;
        for(auto& [id,hp,dir] : alive){
            ans.push_back(hp);
        }
        return ans;
    }
};