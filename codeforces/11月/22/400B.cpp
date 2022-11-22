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

const int N = 200010;

int n,m;
map<int,int> cnt;
string s[1010];

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }
    int res = 0;
    for(int i = 0;i < n;i++){
        int l = 0,r = 0;
        for(int j = 0;j < m;j++){
            if(s[i][j] == 'G'){
                l = j;
            }
            if(s[i][j] == 'S'){
                r = j;
            }
        }
        int diff = r - l;
        //cout << diff << "--" << cnt.count(diff) << endl;
        if(diff > 0 && cnt.count(diff) == 0){
            res++;
            cnt[diff] = 1;
        }else if(diff < 0) {
            res = -1;
            break;
        }
    }
    cout << res << endl;
    return 0;
}