//dp

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6010;

int n,m;
int f[N];

int main(){
    
    cin >> n >> m;
    
    int v,w,s;
    for(int i = 0;i < n;i++){
        cin >> v >> w >> s;
        for(int j = m;j >= v;j--){
            for(int k = 1;k <= s;k++){
                if(j >= v * k){
                    f[j] = max(f[j],f[j - v * k ] + w * k);
                }
            }
        }
    }
    cout << f[m] << endl;
    
    return 0;
}