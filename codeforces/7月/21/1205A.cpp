#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n,m;
int q[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        if(i % 2){
            q[i] = 2 * i;
            q[i + n] = 2 * i - 1;
        }else {
            q[i] = 2 * i - 1;
            q[i + n] = 2 * i;
        }
    }
    if(n % 2 == 0){
        cout << "NO" << endl;
    }else {
        cout << "YES" << endl;
        for(int i = 1;i <= 2 * n;i++){
            cout << q[i] << ' ';
        }
        cout << endl;
    }
}