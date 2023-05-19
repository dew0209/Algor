#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

typedef long long LL;

const int N = 200010;

int n;

void solve(){
    scanf("%d",&n);
    while(true){
        int cur = n;
        int ok = 1;
        while(cur > 0){
            if(ok && cur % 3 == 2)ok = 0;
            cur /= 3;
        }
        if(ok)break;
        ++n;
    }
    printf("%d\n",n);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}