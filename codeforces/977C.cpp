#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N = 100010;

int n,m;
map<int,int> cnt;

int main(){
    cin >> n >> m;
    for(int i  = 1;i <= n;i++){
        int c;cin >> c;
        cnt[c]++;
    }
    int res = -1;
    if(m == 0 && !cnt[1]){
        cout << 1 << endl;
        return 0;
    }else if(m == 0 && cnt[1]){
        cout << -1 << endl;
        return 0;
    }
    for(auto g : cnt){
        m -= g.second;
        if(m < 0){
            res = -1;
            break;
        }
        if(m == 0){
            if(!cnt[g.first + 1])
                res = g.first;
            else res = -1;
            break;
        }
        if(m > 0){
            res = g.first;
        }
       
    }
    cout << res << endl;

    return 0;
}