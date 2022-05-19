#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 100010;

using namespace std;

int n,m;
char s[N];
char ans[N];

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        ans[i] = 0;
    }
    for(int i = 1;i <= (n << 1) - 1;i++){
        scanf("%s",s + 1);
        for(int j = 1;j <= m;j++){
            ans[j] ^= s[j];
        }
    }
    for(int i = 1;i <= m;i++){
        putchar(ans[i]);
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}