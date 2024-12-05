//dp


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20010;

int n,m;
int v[N],w[N];
int f[N];


int main(){
    cin >> m;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> v[i];
        w[i] = v[i];
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= v[i];j--){
            f[j] = max(f[j],f[j - v[i]] + w[i]);
        }
    }
    
    cout << m - f[m] << endl;
    
    return 0;
}