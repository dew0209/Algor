//https://leetcode.cn/problems/furthest-point-from-origin/?envType=daily-question&envId=2026-04-24

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int a = 0;
        int b = 0;
        int c = 0;
        for(int i = 0;i < moves.size();i++){
            char x = moves[i];
            if(x == 'L'){
                a++;
            }else if(x == 'R'){
                b++;
            }else {
                c++;
            }
        }
        
        return abs(a - b) + c;
    }
};