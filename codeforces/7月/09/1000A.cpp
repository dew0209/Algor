#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010;

int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    vector<string> b(n);
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n;i++)cin >> b[i];
    map<string,int> cnta;
    map<string,int> cntb;
    for(int i = 0;i < n;i++)cnta[a[i]]++;
    for(int i = 0;i < n;i++)cntb[b[i]]++;
    int ans = n;
    for(auto c : cnta)ans -= min(c.se,cntb[c.fi]);
    cout << ans << endl;
}