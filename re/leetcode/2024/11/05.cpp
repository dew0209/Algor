//题目链接：https://leetcode.cn/problems/find-the-winning-player-in-coin-game/description/?envType=daily-question&envId=2024-11-05

class Solution {
public:
    string losingPlayer(int x, int y) {
        int a = x;
        int b = y / 4;

        int mv = min(a,b);
        if(mv % 2){
            return "Alice";
        }
        return "Bob";
    }
};