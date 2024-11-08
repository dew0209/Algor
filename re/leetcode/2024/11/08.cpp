//题目链接：https://leetcode.cn/problems/check-if-the-rectangle-corner-is-reachable/description/?envType=daily-question&envId=2024-11-08


typedef long long LL;

class Solution {
public:
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        int n = circles.size();//圆的数量
        vector<bool> vis(n + 1,false);
        for(int i = 0;i < n;i++){
            //当前圆
            int x = circles[i][0],y = circles[i][1],r = circles[i][2];
            //起点，终点是否在圆内
            if(pointInCircle(0,0,x,y,r) || pointInCircle(xCorner,yCorner,x,y,r)){
                return false;
            }
            //是否是左 上边上的圆
            if(!vis[i] && circleIsLeftOrTop(x,y,r,xCorner,yCorner) && dfs(i,circles,vis,xCorner,yCorner)){
                return false;
            }
        }
        return true;
    }

    //点是否在圆内
    bool pointInCircle(int a,int b,int x,int y,int r){
        return (LL)(x - a) * (x - a) + (LL)(y - b) * (y - b) <= (LL) r * r;
    }

    //是否是左 上两边的圆
    bool circleIsLeftOrTop(int x,int y,int r,int xCorner,int yCorner){
        return (abs(x) <= r && y >= 0 && y <= yCorner) || 
                (0 <= x && x <= xCorner && abs(y - yCorner) <= r) ||
                pointInCircle(0,yCorner,x,y,r);

    }

    //是否是下，右边上的
    bool circleIsRightOrBt(int x,int y,int r,int xCorner,int yCorner){
        return (abs(x - xCorner) <= r && y >= 0 && y <= yCorner) || 
                (x >= 0 && x <= xCorner && abs(y) <= r) ||
                pointInCircle(xCorner,0,x,y,r);

    }

    //判断交集是否在矩形内部
    bool isIntersection(int x1,int y1,int r1,int x2,int y2,int r2,int X,int Y){

        return (LL)(x1 - x2) * (x1 - x2) + (LL)(y1 - y2) * (y1 - y2) <= (LL)(r1 + r2) * (r1 + r2) && 
                (LL) x1 * r2 + (LL)r1 * x2 <= (LL)X * (r1 + r2) &&
                (LL) y1 * r2 + (LL)r1 * y2 <= (LL)Y * (r1 + r2);

    }

    bool dfs(int u,vector<vector<int>>& circles,vector<bool>& vis,int xCorner,int yCorner){
        int x = circles[u][0],y = circles[u][1],r = circles[u][2];
        //如果递归到圆在下，右边上，结束
        if(circleIsRightOrBt(x,y,r,xCorner,yCorner)){
            return true;
        }
        vis[u] = true;
        int n = circles.size();
        for(int i = 0;i < n;i++){
            int a = circles[i][0],b = circles[i][1],c = circles[i][2];
            //两个圆有交集 且交集在矩形内
            if(!vis[i] && isIntersection(x,y,r,a,b,c,xCorner,yCorner) && dfs(i,circles,vis,xCorner,yCorner)){
                return true;
            }
        }
        return false;
    }

};