#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int q[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
    }
    sort(q + 1,q + 1 + n);
    for(int i = 1;i <= n;i += 2){
        cout << q[i] << ' ';
    }
    int j = n % 2 ? n - 1 : n;
    for(;j >= 1;j -= 2){
        cout << q[j] << ' ';
    }
    cout << endl;
}