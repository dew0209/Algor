//并查集

/*
    思路：
        能围成一个圈，那么形成圈的这次操作，肯定是将断点连接起来，那么在操作之前，两个断点就在一个连通块。
        所以，我们需要不断去合并连通块。
        涉及到的小tips：
            将二维的点a(x,y)转化成为一维：b = x * n + y; 一维再转化为二维：(b / n,b % n);这个再起始为(0,0)的时候有用，
            在起始为(1,1)的时候，并不适用，例如：3 * 3的点(2,3) b = 2 * 3 + 3 = 9 反算：(9 / 3,9 % 3) = (3,0);
                                              3 * 3d的点(1,2) b = 1 * 3 + 2 = 5 反算：(5 / 3,5 % 3) = (1,2);
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;


int n,m;
int p[N];

int find(int u){
    if(p[u] != u){
        p[u] = find(p[u]);
    }
    return p[u];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= N;i++)p[i] = i;
    int res = 0;
    for(int i = 1;i <= m;i++){
        int a,b;scanf("%d%d",&a,&b);
        char op[2];scanf("%s",op);
        int da = a * n + b;
        int db = 0;
        if(*op == 'D'){
            db = (a + 1) * n + b;
        }else {
            db = a * n + b + 1;
        }
        da = find(da);
        db = find(db);
        if(da == db && res == 0){
            res = i;
        }else {
            p[da] = db;
        }
    }
    if(res){
        printf("%d\n",res);
    }else {
        puts("draw");
    }
    return 0;
}