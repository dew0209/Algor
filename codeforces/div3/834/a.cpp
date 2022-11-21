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

const int N = 5010;

string s;

void solve(){
    string t;cin >> t;
    if(s.find(t) != -1){
        cout << "YES";
    }else {
        cout << "NO";
    }
}

int main(){
    for(int i = 0;i < 1000;i++){
        s += "Yes";
    }
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}