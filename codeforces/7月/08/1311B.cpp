#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        a.push_back(c);
    }
    vector<int> pos(n);
    for(int i = 0;i < m;i++){
        int pp;cin >> pp;
        pos[pp - 1] = 1;
    } 
    for(int i = 0;i < n;i++){
        if(pos[i] == 0)continue;
        int j = i;
        while(j < n && pos[j])j++;
        sort(a.begin() + i,a.begin() + j + 1);
        i = j;
    }
    bool ok = true;
    for(int i = 0;i < n - 1;i++){
        ok &= a[i] <= a[i + 1];
    }
    if(ok)cout << "YES";
    else cout << "NO";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}