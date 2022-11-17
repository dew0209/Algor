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

const int N = 100010;

int n,m;
int c[N],t[N],v[N];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> c[i] >> t[i];
    }
    int ans = 0;
    int st = 0;
    for(int i = 1;i <= m;i++){
        cin >> v[i];
        while(v[i] > ans){
            ++st;
            ans += c[st] * t[st];
        }
        cout << st << endl;
    }
    return 0;
}