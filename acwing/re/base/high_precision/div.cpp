#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define pb push_back

using namespace std;

const int N = 100010;

int n,m;
char ca[N];

vector<int> mul(vector<int> a,int b,int &r){
    vector<int> c;
    for(int i = 0;i < a.size();i++){
        r = r * 10 + a[i];
        c.pb(r / b);
        r %= b;
    }
    reverse(c.begin(),c.end());
    while(c.size() > 1 && c.back() == 0)c.pop_back();
    reverse(c.begin(),c.end());
    return c;
}

int main(){
    int b;
    scanf("%s%d",ca,&b);
    n = strlen(ca);
    vector<int> a;
    int r = 0;
    for(int i = 0;i < n;i++){
        a.pb(ca[i] - '0');
    }
    auto c = mul(a,b,r);
    for(int i = 0;i < c.size();i++)printf("%d",c[i]);
    printf("\n%d\n",r);
    return 0;
}