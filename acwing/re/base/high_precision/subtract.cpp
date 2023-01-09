#include <iostream>
#include <cstring>
#include <vector>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 100010;

int n,m;
char ca[N],cb[N];

int check(char a[],char b[]){
    int n = strlen(a);
    int m = strlen(b);
    if(n != m)return n > m;
    for(int i = 0;i < n;i++){
        if(a[i] != b[i])return a[i] > b[i];
    }
    return 0;
}

vector<int> subtract(vector<int> a,vector<int> b){
    vector<int> c;
    int t = 0;
    for(int i = 0;i < a.size();i++){
        t += a[i];
        if(i < b.size())t -= b[i];
        c.pb((t + 10) % 10);
        if(t < 0)t = -1;
    }
    return c;
}

int main(){
    scanf("%s%s",ca,cb);
    n = strlen(ca);
    m = strlen(cb);
    if(check(ca,cb)){
        swap(ca,cb);
        printf("-");
    }
    vector<int> a;
    vector<int> b;
    for(int i = n - 1;i >= 0;i--)a.pb(ca[i] - '0');
    for(int i = m - 1;i >= 0;i--)b.pb(cb[i] - '0');
    auto c = subtract(a,b);
    reverse(c.begin(),c.end());
    for(int i = 0;i < c.size();i++){
        printf("%d",c[i]);
    }
    printf("%d\n");
    return 0;
}