#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>

typedef long long LL;

using namespace std;

const int N = 1000010;

int n;
LL q[N];
set<double> cnt;
int st[N];
int p[N];
int idx = 0;

int init(){
    int n = 1e6;
    for(int i = 2;i <= n;i++){
        if(!st[i]){
            p[idx++] = i;cnt.insert(i);
        }
        for(int j = 0;p[j] <= n / i;j++){
            st[p[j] * i] = true;
            if(i % p[j] == 0)break;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        LL c;scanf("%lld",&c);
        q[i] = c;
    }
    init();
    for(int i = 1;i <= n;i++){
        if(cnt.find(sqrt(q[i])) != cnt.end()){
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }
    return 0;
}