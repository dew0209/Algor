#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7;

int n;
int q[10];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        q[c]++;
    }
    n /= 3;
    // 1 2 4
    // 1 2 6
    // 1 3 6
    if(q[1] == n && q[2] + q[3] == n && q[2] >= q[4] && q[4] + q[6] == n && q[6] >= q[3]){
        while(q[4]--)q[2]--,cout << "1 2 4" << endl;
        while(q[2]--)cout << "1 2 6" << endl;
        while(q[3]--)cout << "1 3 6" << endl;
    }else cout << "-1" << endl;

    return 0;
}