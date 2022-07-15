#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n;
int q[N];

int main(){
    cin >> n;
    for(int i = 2;i <= n + 1;i++){
        if(!q[i]){
            for(int j = 2;j <= (n + 1) / i;j++){
                q[i * j] = 1;
                
            }
        }
    }
    if(n == 1)cout << 1 << endl;
    else cout << 2 << endl;
    for(int i = 2;i <= n + 1;i++){
        if(!q[i])cout << "1 ";
        else cout << "2 ";
    }
    cout << endl;
}