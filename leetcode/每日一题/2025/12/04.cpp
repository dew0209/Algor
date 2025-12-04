//https://leetcode.cn/problems/count-collisions-on-a-road/?envType=daily-question&envId=2025-12-04






//方法一
class Solution {
public:
    int countCollisions(string directions) {
        int l = 0;
        int r = 0;
        int s = 0;
        int res = 0;
        int n = directions.size();
        stack<char> q;
        for(int i = 0;i < n;i++){
            char x = directions[i];
            while(!q.empty()){
                char top = q.top();
                if(top == 'R' && x == 'S'){
                    res++;
                    q.pop();
                }else if(top == 'R' && x == 'L'){
                    res += 2;
                    q.pop();
                    x = 'S';
                }else if(top == 'S' && x == 'L'){
                    res++;
                    q.pop();
                    x = 'S';
                }else {
                    break;
                }
            }
            q.push(x);
        }
        return res;
    }
};


//方法二：官方题解

class Solution {
public:
    int countCollisions(string directions) {
        int r = -1;
        int res = 0;
        int n = directions.size();
        for(int i = 0;i < n;i++){
            char x = directions[i];
            if(x == 'L'){
                if(r >= 0){
                    res += r + 1;
                    r = 0;
                }
            }else if(x == 'S'){
                if(r >= 0){
                    res += r;
                }
                r = 0;
            }else {
                if(r >= 0){
                    r++;
                }else {
                    r = 1;
                }
            }
        }
        return res;
    }
};


//方法三：左左左左左左左左xxxxxxxx右右右右右右右右右右右右右右右右  中间的必碰撞