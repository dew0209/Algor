//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


const int N = 1010;

int n,m;
int f[N];

int main(){
    
    cin >> n >> m;
    
    int v,w,s;
    
    for(int i = 1;i <= n;i++){
        cin >> v >> w >> s;
        
        if(s == -1){
            for(int j = m;j >= v;j--){
                f[j] = max(f[j],f[j - v] + w);
            }
        }else if(s == 0){
            for(int j = v;j <= m;j++){
                f[j] = max(f[j],f[j - v] + w);
            }
        }else {
            int k = 1;
            while(k <= s){
                for(int j = m;j >= v * k;j--){
                    f[j] = max(f[j],f[j - v * k] + k * w);
                }
                s -= k;
                k = k * 2;
            }
            if(s){
                for(int j = m;j >= v * s;j--){
                    f[j] = max(f[j],f[j - v * s] + s * w);
                }
            }
            
        }
    }
    cout << f[m] << endl;
    return 0;
}