//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int f[N];
int g[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> g[i];
    }
    int res = 0;
    for(int i = 1;i <= n;i++){
        f[i] = g[i];
        for(int j = 1;j < i;j++){
            if(g[i] > g[j]){
                f[i] = max(f[i],f[j] + g[i]);
            }
        }
        res = max(res,f[i]);
    }
    cout << res << endl;
    
    return 0;
}