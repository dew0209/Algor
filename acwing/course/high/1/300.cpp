//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 5010;

int n,s;
LL sumc[N],sumt[N];
LL f[N];

int main(){
    
    cin >> n >> s;
    
    for(int i = 1;i <= n;i++){
        int t,c;
        cin >> t >> c;
        sumt[i] = sumt[i - 1] + t;
        sumc[i] = sumc[i - 1] + c;
    }
    
    memset(f,0x3f,sizeof f);
    
    f[0] = 0;
    
    for(int i = 1;i <= n;i++){
        
        for(int j = 0;j < i;j++){
            
            f[i] = min(f[i],f[j] + sumt[i] * (sumc[i] - sumc[j]) + s * (sumc[n] - sumc[j]));
            
        }
        
    }
    
    cout << f[n] << endl;
    
    return 0;
}