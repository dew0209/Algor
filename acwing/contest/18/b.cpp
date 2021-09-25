#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n;
int f[N];

int main(){
    cin >> n;
    f[1] = 1;
    for(int i = 2;i <= n;i++){
        f[i] = f[i - 1] + (i - 1) * 12;
    }
    cout << f[n] << endl;
}