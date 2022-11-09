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
string str[2010];
int cnt[2010];

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> str[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(str[i][j] == '1'){
                cnt[j]++;
            }
        }
    }
    int res = 0;
    for(int i = 0;i < n;i++){
        //减少
        for(int j = 0;j < m;j++){
            if(str[i][j] == '1'){
                cnt[j]--;
            }
        }
        bool ok = false;
        //判断
        for(int j = 0;j < m;j++){
            if(cnt[j] == 0){
                ok = true;
                break;
            }
        }
        //复原
        for(int j = 0;j < m;j++){
            if(str[i][j] == '1'){
                cnt[j]++;
            }
        }
        if(!ok){
            res++;
        }
    }
    if(res >= 1){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
    return 0;
}