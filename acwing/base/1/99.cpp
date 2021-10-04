/*
 * 激光炸弹
 */
#include <iostream>

using namespace std;

const int N = 5010;

int n,m;
int h[N][N];

int main(){
    cin >> n >> m;
    m = min(5001,m);
    int wd = 5001,he = 5001;
    for(int i = 0;i < n;i++){
        int a,b,w;cin >> a >> b >> w;
        a++;b++;
        h[a][b] += w;
        wd = max(a,wd);
        he = max(b,he);
    }
    for(int i = 1;i <= wd;i++)
        for(int j = 1;j <= he;j++)
            h[i][j] += h[i - 1][j] + h[i][j - 1] - h[i - 1][j - 1];
    int res = 0;
    //m++;
    for(int i = m;i <= wd;i++){
        for(int j = m;j <= he;j++){
            res = max(res,h[i][j] - h[i][j - m] - h[i - m][j] + h[i - m][j - m]);
        }
    }
    cout << res << endl;

    return 0;
}