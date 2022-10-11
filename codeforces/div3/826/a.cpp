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

const int N = 1000010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m;
int q[N];

void solve(){
    string endCh = "SML";
    string s,t;cin >> s >> t;
    n = s.size();
    int cs = 0,ct = 0;
    int cnts = 0,cntt = 0;
    for(int i = n - 1;i >= 0;i--){
        //寻找结尾的字母
        if(i == n - 1){
            for(int j = 0;j < 3;j++){
                if(s[i] == endCh[j]){
                    cs = j;
                }
            }
        }else {
            cnts++;
        }
    }
    n = t.size();
    for(int i = n - 1;i >= 0;i--){
        //寻找结尾的字母
        if(i == n - 1){
            for(int j = 0;j < 3;j++){
                if(t[i] == endCh[j]){
                    ct = j;
                }
            }
        }else {
            cntt++;
        }
    }
    //cout << cnts << "-- " << cntt << endl;
    //cout << cs << "-- " << ct << endl;
    if(cs > ct){
        cout << ">";
    }else if(cs < ct){
        cout << "<";
    }else {
        if(cnts == cntt){
            cout << "=";
        }else if(cs == 0){
            if(cnts > cntt){
                cout << "<";
            }else {
                cout << ">";
            }
        }else if(cs == 2){
            if(cnts > cntt){
                cout << ">";
            }else {
                cout << "<";
            }
        }
    }
}

int main(){
    int T = 1;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}