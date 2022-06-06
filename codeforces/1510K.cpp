#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2010;

int n,m;
int q[N];

int main(){
    cin >> n;
    for(int i = 1;i <= 2 * n;i++)cin >> q[i];
    int cyc = (n % 2 == 0 ? 4 : 2 * n),pos = -1;
    for(int i = 0;i < cyc;i++){
        if(is_sorted(q + 1,q + n + n + 1)){
            pos = i;
            break;
        }
        if(i % 2)for(int i = 1;i <= n;i++)swap(q[i],q[n + i]);
        else for(int i = 1;i <= n + n;i += 2)swap(q[i],q[i + 1]);
    }
    cout << min(pos,cyc - pos) << endl;
}