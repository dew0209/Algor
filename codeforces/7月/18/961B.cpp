#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int q[N];
int st[N];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> q[i];
    for(int i = 1;i <= n;i++)cin >> st[i];
    int baseSum = 0;
    for(int i = 1;i <= n;i++){
        if(st[i] == 1){
            baseSum += q[i];
            q[i] = 0;
        }
        q[i] += q[i - 1];
    }
    int addSum = 0;
    for(int i = m;i <= n;i++){
        addSum = max(addSum,q[i] - q[i - m]);
    }
    cout << baseSum + addSum << endl;
}