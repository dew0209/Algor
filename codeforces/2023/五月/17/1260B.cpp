#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200010;

int n,m;

void solve(){
    scanf("%d%d",&n,&m);
    if((n + m) % 3 == 0 && (n * 2 >= m && m * 2 >= n)){
        puts("YES");
    }else {
        puts("NO");
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}