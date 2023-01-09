#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 100010;

int n,m;
char ca[N],cb[N];

vector<int> big_add(vector<int> a,vector<int> b){
    vector<int> c;
    int t = 0;
    for(int i = 0;i < a.size() || i < b.size();i++){
        if(i < a.size())t += a[i];
        if(i < b.size())t += b[i];
        c.pb(t % 10);
        t /= 10;
    }
    if(t)c.pb(t);
    return c;
}

int main(){
    scanf("%s%s",ca,cb);
    n = strlen(ca);
    m = strlen(cb);
    vector<int> a;
    vector<int> b;
    for(int i = n - 1;i >= 0;i--){
        a.pb(ca[i] - '0');
    }
    for(int i = m - 1;i >= 0;i--){
        b.pb(cb[i] - '0');
    }
    auto c = big_add(a,b);
    reverse(c.begin(),c.end());
    for(int i = 0;i < c.size();i++){
        printf("%d",c[i]);
    }
    return 0;
}