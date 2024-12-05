//dp

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int n;
int f[N];
int v[4] = {10,20,50,100};

int main(){
    
    cin >> n;
    
    f[0] = 1;
    
    for(int i = 0;i < 4;i++){
        for(int j = v[i];j <= n;j++){
            f[j] += f[j - v[i]];
        }
    }
    cout << f[n] << endl;
    return 0;
}