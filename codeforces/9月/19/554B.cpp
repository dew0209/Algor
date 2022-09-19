#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

string s[N];
int n;

int main(){
    cin >> n;
    int res = 0;
    int ans = 0;
    for(int i = 0;i < n;i++)cin >> s[i];
    for(int i = 0;i < n;i++){
        res = 0;
        for(int j = i + 1;j < n;j++){
            if(i != j && s[i] == s[j]){
                res++;
            }
        }
        ans = max(res + 1,ans);
    }
    cout << ans << endl;
    return 0;
}