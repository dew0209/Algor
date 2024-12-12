//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30010;

int n,m;
int v[N],w[N];
int f[N];

int main(){
    cin >> n >> m;
    
    for(int i = 1;i <= m;i++){
        int a,b;cin >> a >> b;
        v[i] = a;
        w[i] = a * b;
    }
    
    for(int i = 1;i <= m;i++){
        for(int j = n;j >= v[i];j--){
            f[j] = max(f[j],f[j - v[i]] + w[i]);
        }
    }
    cout << f[n] << endl;
    return 0;
}