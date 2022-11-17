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

int n,m;
int res[N];

int main(){
    cin >> n >> m;
    string s;cin >> s;
    int ok = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '.'){
            s[i] = '0';
            if(i + m < n && s[i + m] == '0' || i - m >= 0 && s[i - m] == '0'){
                s[i] = '1';
            }
        }
        if(i + m < n && s[i] != s[i + m]){
            ok = 1;
        }
    }
    if(!ok)cout << "NO" << endl;
    else cout << s << endl;
    return 0;
}