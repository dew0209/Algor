//https://leetcode.cn/problems/robot-return-to-origin/description/?envType=daily-question&envId=2026-04-05

int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0,y = 0;
        for(int i = 0;i < moves.size();i++){
            
            char c = moves[i];
            int id = 0;
            if(c == 'D'){
                id = 0;
            }else if (c == 'R'){
                id = 1;
            }else if(c == 'U'){
                id = 2;
            }else if(c == 'L'){
                id = 3;
            }
            x = x + dx[id];
            y = y + dy[id];
        }
        return x == 0 && y == 0;
    }
};