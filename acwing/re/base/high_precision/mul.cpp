#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

typedef long long LL;

#define pb push_back

using namespace std;

const int N = 100010;

int n,m;
char ca[N];

vector<int> big_mul(vector<int> a,int b){
    vector<int> c;
    LL t = 0;
    for(int i = 0;i < a.size();i++){
        t = t + a[i] * b;
        c.pb(t % 10);
        t /= 10;
    }
    while(t){
        c.pb(t % 10);
        t /= 10;
    }
    while(c.size() > 1 && c.back() == 0)c.pop_back();
    reverse(c.begin(),c.end());
    return c;
}

int main(){
    int b;
    scanf("%s%d",ca,&b);
    vector<int> a;
    n = strlen(ca);
    for(int i = n - 1;i >= 0;i--)a.pb(ca[i] - '0');
    auto c = big_mul(a,b);
    for(int i = 0;i < c.size();i++)printf("%d",c[i]);
    printf("\n");
    return 0;
}