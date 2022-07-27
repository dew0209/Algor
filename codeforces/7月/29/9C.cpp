#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

int n;
int cnt;

void dfs(int u){
    if(u > n)return;
    cnt++;
    dfs(u * 10);
    dfs(u * 10 + 1);
}

int main(){
    cin >> n;
    dfs(1);
    cout << cnt << endl;
}