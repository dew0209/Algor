//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 3010;

int n,m;
LL f[N];

int main(){
    
    cin >> n >> m;
    
    f[0] = 1;
    int v;
    
    for(int i = 0;i < n;i++){
        
        cin >> v;
        
        for(int j = v;j <= m;j++){
            f[j] = f[j] + f[j - v];
        }
    }
    
    cout << f[m] << endl;
    return 0;
}