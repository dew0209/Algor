//题目链接：https://leetcode.cn/problems/snake-in-matrix/description/?envType=daily-question&envId=2024-11-21

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int m = commands.size();

        int x = 0,y = 0;
        for(int i = 0;i < commands.size();i++){

            if(commands[i] == "UP"){
                x--;
            }
            if(commands[i] == "DOWN"){
                x++;
            }

            if(commands[i] == "LEFT"){
                y--;
            }

            if(commands[i] == "RIGHT"){
                y++;
            }
        }
        return x * n + y;
    }
};