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

int main(){
    string s,t;
    cin >> s >> t;
    int a = 0,b = 0,c = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '7')a++;
        if(t[i] == '7')b++;
        if(s[i] != t[i])c++;
    }
    int res = abs(a - b);
    int diff = abs(res - c);
    cout << res + diff / 2 << endl;
    return 0;
}