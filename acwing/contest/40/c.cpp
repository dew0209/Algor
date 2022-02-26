#include <iostream>

typedef long long LL;

using namespace std;

LL n,m;
int a[30],b[30],c[30],ans[30];
int lena,lenb;

bool dfs(int idx,int f){
    if(idx < 0)return 1;
    for(int i = 9;i >= 0;i--){
        if(f && i <= b[idx] && c[i]){
            c[i]--;
            ans[idx] = i;
            if(dfs(idx - 1,i == b[idx])){
                return 1;
            }
            c[i]++;
        }
        if(!f && c[i]){
            c[i]--;
            ans[idx] = i;
            if(dfs(idx - 1,0))return 1;
            c[i]++;
        }
    }
    return 0;
}

int main(){
    cin >> n >> m;
    while(n){
        a[lena++] = n % 10;
        c[n % 10]++;
        n /= 10;
    }
    while(m){
        b[lenb++] = m % 10;
        m /= 10;
    }
    if(lena != lenb){
        for(int i = 9;i >= 0;i--){
            while(c[i]){
                cout << i;
                c[i]--;
            }
        }
        return 0;
    }
    dfs(lena - 1,1);
    for(int i = lena - 1;i >= 0;i--)cout << ans[i];
    cout << endl;

    return 0;
}