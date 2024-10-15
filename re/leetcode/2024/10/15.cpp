//题目链接：https://leetcode.cn/problems/maximum-height-of-a-triangle/description/?envType=daily-question&envId=2024-10-15


class Solution {
public:
    int getRes(int red,int blue,int t){
        int res = 0;
        int st = 1;
        while(true){
            if(t == 1){
                if(blue < st){
                    break;
                }
                res++;
                blue -= st;
                t = 0;
                st++;
            }else {
                if(red < st){
                    break;
                }
                res++;
                red -= st;
                t = 1;
                st++;
            }
        }
        return res;
    }
    int maxHeightOfTriangle(int red, int blue) {
        
        // int a = getRes(blue,red,0);
        // int b = getRes(blue,red,1);

        int a = min(2 * int(sqrt(red)) - 1,2 * int((-1 + sqrt(1 + 4 * blue)) / 2)) + 1;
        int b = min(2 * int(sqrt(blue)) - 1,2 * int((-1 + sqrt(1 + 4 * red)) / 2)) + 1;


        return max(a,b);

    }
};