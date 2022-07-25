#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010;

int q[N];
int p[N];

int main(){
    int n;cin >> n;
    int idx = 0;
    for(int i = 0;i < n;i++){
        cin >> p[i];
    }
    sort(p,p + n);
    for(int i = 0;i < n;i++){
        int j = 0;
        while(j < idx && q[j] >= p[i])j++;
        q[j] = p[i];
        if(j >= idx)idx++;
    }
    cout << idx << endl;
}