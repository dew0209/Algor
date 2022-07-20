#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

typedef long long LL;

using namespace std;

const int N = 100010;

int n;

int main(){
    int n;cin >> n;
    map<string,int> l;
    l["polycarp"] = 1;
    int ans = 1;
    string a,b,c;
    while(n--){
        cin >> a >> b >> c;
        for(int i = 0;i < a.size();i++)a[i] = tolower(a[i]);
        for(int i = 0;i < c.size();i++)c[i] = tolower(c[i]);
        int e = l[c] + 1;
        if(e > ans)ans = e;
        l[a] = e;
    }
    cout << ans << endl;
}