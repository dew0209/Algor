#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 100010;

int n,m;
int q[N];

int main(){
    cin >> n;
    bool ok = false;
    bool flag = false;
    for(int i = 0;i < n;i++){
        cin >> q[i];
        if(q[i] % 2 == 0){
            ok = true;
        }
        if(q[i] % 2 == 1){
            flag = true;
        }
    }
    if(ok && flag){
        sort(q,q + n);
    }
    for(int i = 0;i < n;i++){
        cout << q[i] << ' ';
    }
    cout << endl;
}