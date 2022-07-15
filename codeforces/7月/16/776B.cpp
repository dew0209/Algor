#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n;
int q[N];

int main(){
    cin >> n;
    bool ok = false;
    for(int i = 2;i <= n + 1;i++){
        if(!q[i]){
            for(int j = 2;j <= (n + 1) / i;j++){
                q[i * j] = 1;
                ok = true;
            }
        }
    }
    if(ok)cout << 2 << endl;
    else cout << 1 << endl;
    for(int i = 2;i <= n + 1;i++){
        if(!q[i])cout << "1 ";
        else cout << "2 ";
    }
    cout << endl;
}