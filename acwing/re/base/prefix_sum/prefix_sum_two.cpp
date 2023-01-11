#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;

int n,m,query;
int q[N][N];

int main(){
    scanf("%d%d%d",&n,&m,&query);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            scanf("%d",&q[i][j]);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            q[i][j] += q[i][j - 1] + q[i - 1][j] - q[i - 1][j - 1];
    while(query--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",q[x2][y2] - q[x2][y1 - 1] - q[x1 - 1][y2] + q[x1 - 1][y1 - 1]);
    }
    return 0;
}