#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 210,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int main(){
    string s,s1;cin >> s >> s1;
    int t = 0;
    int x = s.find(s1);
    while(x >= 0){
        t++;
        x = s.find(s1,x + s1.size());
    }
    cout << t << endl;
}