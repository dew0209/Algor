#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m;
int sx,sy;
string s[100];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int p[4] = {0,1,2,3};

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++)cin >> s[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(s[i][j] == 'S'){
                sx = i;
                sy = j;
                break;
            }
        }
    }
    int res = 0;
    string ins;cin >> ins;
    for(int i = 0;i < 24;i++){
        int x = sx,y = sy;
        for(char c : ins){
            int id = p[c ^ 48];
            x += dx[id];
            y += dy[id];
            if(x < 0 || x >= n || y < 0 || y >= m)break;
            if(s[x][y] == '#')break;
            if(s[x][y] == 'E'){
                res++;
                break;
            }
        }
        next_permutation(p,p + 4);
    }
    cout << res << endl;

    return 0;
}