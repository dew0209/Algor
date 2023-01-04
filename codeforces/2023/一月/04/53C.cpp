#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

using namespace std;

int q[10010];

int main(){
    int n;cin >> n;
    int st = 1;
    int ed = n;
    for(int i = 0;i < n;i++){
        if(i % 2 == 0){
            q[i] = st++;
        }else q[i] = ed--;
    }
    for(int i = 0;i < n;i++){
        cout << q[i] << ' ';
    }
    cout << endl;
    return 0;
}